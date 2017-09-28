// Design and implement a data structure for Least Frequently Used (LFU) cache. It should support the following operations: get and put.
//
//
//
// get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
// put(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity, it should invalidate the least frequently used item before inserting a new item. For the purpose of this problem, when there is a tie (i.e., two or more keys that have the same frequency), the least recently used key would be evicted.
//
//
// Follow up:
// Could you do both operations in O(1) time complexity?
//
// Example:
//
// LFUCache cache = new LFUCache( 2 /* capacity */ );
//
// cache.put(1, 1);
// cache.put(2, 2);
// cache.get(1);       // returns 1
// cache.put(3, 3);    // evicts key 2
// cache.get(2);       // returns -1 (not found)
// cache.get(3);       // returns 3.
// cache.put(4, 4);    // evicts key 1.
// cache.get(1);       // returns -1 (not found)
// cache.get(3);       // returns 3
// cache.get(4);       // returns 4


class LFUCache {
private:
    int cap, minFreq;
    unordered_map<int, int> values;                // key -> value
    unordered_map<int, int> freq;                  // key -> frequent
    unordered_map<int, list<int>> reverse;         // freq -> key
    unordered_map<int, list<int>::iterator> iters; // key -> iteration of doctor
    
    inline void addLinkedList(int key, int _freq) {
        if (reverse.find(_freq) == reverse.end()) {
            list<int> l(1, key);
            reverse[_freq] = l;
        }
        else {
            reverse[_freq].push_front(key);
        }
        iters[key] = reverse[_freq].begin();
        freq[key] = _freq;
    }
    
    inline void use(int key) {
        int f = freq[key];
        int nf = f + 1;
        reverse[f].erase(iters[key]);
        if (reverse[f].size() == 0) {
            reverse.erase(f);
            if (f == minFreq) minFreq++;
        }
        addLinkedList(key, nf);
    }
    
public:
    LFUCache(int capacity) {
        this->cap = capacity;
    }
    
    int get(int key) {
        if (this->cap <= 0) return -1;
        if (values.find(key) == values.end()) 
            return -1;
        else {
            use(key);
            return values[key];
        }
    }
    
    void put(int key, int value) {
        if (this->cap <= 0) return;
        if (freq.empty()) minFreq = 1;
        if (values.find(key) == values.end()) {  // New key with frequent 1
            if (values.size() >= cap) {  // Delete not frequent key
                int toDel = reverse[minFreq].back();
                reverse[minFreq].pop_back();
                values.erase(toDel);
                iters.erase(toDel);
                freq.erase(toDel);
                if (reverse[minFreq].size() == 0) {
                    reverse.erase(minFreq);
                }
            }
            values[key] = value;
            freq[key] = 1;
            addLinkedList(key, 1);
            minFreq = 1;
        }
        else {  // Add 1 to an existed frequent
            values[key] = value;
            use(key);
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache obj = new LFUCache(capacity);
 * int param_1 = obj.get(key);
 * obj.put(key,value);
 */
