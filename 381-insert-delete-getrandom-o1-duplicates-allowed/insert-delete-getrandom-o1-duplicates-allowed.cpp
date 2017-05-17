// Design a data structure that supports all following operations in average O(1) time.
// Note: Duplicate elements are allowed.
//
//
// insert(val): Inserts an item val to the collection.
// remove(val): Removes an item val from the collection if present.
// getRandom: Returns a random element from current collection of elements. The probability of each element being returned is linearly related to the number of same value the collection contains.
//
//
//
// Example:
//
// // Init an empty collection.
// RandomizedCollection collection = new RandomizedCollection();
//
// // Inserts 1 to the collection. Returns true as the collection did not contain 1.
// collection.insert(1);
//
// // Inserts another 1 to the collection. Returns false as the collection contained 1. Collection now contains [1,1].
// collection.insert(1);
//
// // Inserts 2 to the collection, returns true. Collection now contains [1,1,2].
// collection.insert(2);
//
// // getRandom should return 1 with the probability 2/3, and returns 2 with the probability 1/3.
// collection.getRandom();
//
// // Removes 1 from the collection, returns true. Collection now contains [1,2].
// collection.remove(1);
//
// // getRandom should return 1 and 2 both equally likely.
// collection.getRandom();


class RandomizedCollection {
private:
    vector<int> list;
    unordered_map<int, vector<int>> m;
    
public:
    /** Initialize your data structure here. */
    RandomizedCollection() {
        list.clear();
        m.clear();
    }
    
    /** Inserts a value to the collection. Returns true if the collection did not already contain the specified element. */
    bool insert(int val) {
        bool res = m.find(val) == m.end();
        int pos = list.size();
        list.push_back(val);
        if (res) {
            vector<int> v = {pos};
            m[val] = v;
        }
        else {
            res = m[val].size() == 0;
            m[val].push_back(pos);
        }
        return res;
    }
    
    /** Removes a value from the collection. Returns true if the collection contained the specified element. */
    bool remove(int val) {
        auto it = m.find(val);
        if (it == m.end()) return false;
        if (it->second.size() == 0) return false;
        int pos = it->second[it->second.size() - 1];
        it->second.pop_back();
        int len = list.size();
        int last = list[len - 1];
        list.pop_back();
        list[pos] = last;
        for (int i = 0; i < m[last].size(); i++) {
            if (m[last][i] == len - 1) {
                m[last][i] = pos;
                break;
            }
        }
        return true;
    }
    
    /** Get a random element from the collection. */
    int getRandom() {
        return list[rand() % list.size()];
    }
};

/**
 * Your RandomizedCollection object will be instantiated and called as such:
 * RandomizedCollection obj = new RandomizedCollection();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
