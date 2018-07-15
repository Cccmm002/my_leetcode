// Implement a data structure supporting the following operations:
//
//
//
// Inc(Key) - Inserts a new key  with value 1. Or increments an existing key by 1. Key is guaranteed to be a non-empty string.
// Dec(Key) - If Key's value is 1, remove it from the data structure. Otherwise decrements an existing key by 1. If the key does not exist, this function does nothing. Key is guaranteed to be a non-empty string.
// GetMaxKey() - Returns one of the keys with maximal value. If no element exists, return an empty string "".
// GetMinKey() - Returns one of the keys with minimal value. If no element exists, return an empty string "".
//
//
//
//
// Challenge: Perform all these in O(1) time complexity.
//


typedef struct Node {
    int freq;
    unordered_set<string> list;
    Node *next;
    Node *prev;
    
    Node() {
        freq = 1;
        next = NULL;
        prev = NULL;
    }
}*pNode;

class AllOne {
private:
    unordered_map<string, pNode> dict;
    pNode lowest, highest;
    
public:
    /** Initialize your data structure here. */
    AllOne() {
        lowest = NULL;
        highest = NULL;
    }
    
    /** Inserts a new key <Key> with value 1. Or increments an existing key by 1. */
    void inc(string key) {
        if (dict.find(key) == dict.end()) {
            if (lowest == NULL || lowest->freq != 1) {
                pNode one = new Node();
                one->list.insert(key);
                dict[key] = one;
                if (lowest == NULL) {
                    lowest = one;
                    highest = one;
                }
                else {
                    lowest->prev = one;
                    one->next = lowest;
                    lowest = one;
                }
            }
            else {
                dict[key] = lowest;
                lowest->list.insert(key);
            }
        }
        else {
            pNode cur = dict[key];
            if (cur->next == NULL || cur->next->freq != cur->freq + 1) {
                pNode nn = new Node();
                nn->freq = cur->freq + 1;
                nn->next = cur->next;
                if (cur->next != NULL) cur->next->prev = nn;
                nn->prev = cur;
                cur->next = nn;
                if (highest == cur) highest = nn;
            }
            dict[key] = cur->next;
            cur->next->list.insert(key);
            cur->list.erase(key);
            if (cur->list.size() == 0) {
                cur->next->prev = cur->prev;
                if (cur->prev != NULL) cur->prev->next = cur->next;
                if (lowest == cur) lowest = cur->next;
                delete cur;
            }
        }
    }
    
    /** Decrements an existing key by 1. If Key's value is 1, remove it from the data structure. */
    void dec(string key) {
        if (dict.find(key) == dict.end()) return;
        pNode cur = dict[key];
        if (cur->freq != 1 && (cur->prev == NULL || cur->prev->freq != cur->freq - 1)) {
            pNode nn = new Node();
            nn->freq = cur->freq - 1;
            nn->prev = cur->prev;
            if (cur->prev != NULL) cur->prev->next = nn;
            nn->next = cur;
            cur->prev = nn;
            if (lowest == cur) lowest = nn;
        }
        else if (cur->freq == 1) {
            dict.erase(key);
            cur->list.erase(key);
            if (cur->list.size() == 0) {
                lowest = cur->next;
                if (highest == cur) highest = NULL;
                if (cur->next != NULL) cur->next->prev = NULL;
                delete cur;
            }
            return;
        }
        dict[key] = cur->prev;
        cur->prev->list.insert(key);
        cur->list.erase(key);
        if (cur->list.size() == 0) {
            cur->prev->next = cur->next;
            if (cur->next != NULL) cur->next->prev = cur->prev;
            if (highest == cur) highest = cur->prev;
            delete cur;
        }
    }
    
    /** Returns one of the keys with maximal value. */
    string getMaxKey() {
        if (highest == NULL) return "";
        else return *(highest->list.begin());
    }
    
    /** Returns one of the keys with Minimal value. */
    string getMinKey() {
        if (lowest == NULL) return "";
        else return *(lowest->list.begin());
    }
};

