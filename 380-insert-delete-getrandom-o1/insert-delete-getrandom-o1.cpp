// Design a data structure that supports all following operations in average O(1) time.
//
//
//
// insert(val): Inserts an item val to the set if not already present.
// remove(val): Removes an item val from the set if present.
// getRandom: Returns a random element from current set of elements. Each element must have the same probability of being returned.
//
//
//
// Example:
//
// // Init an empty set.
// RandomizedSet randomSet = new RandomizedSet();
//
// // Inserts 1 to the set. Returns true as 1 was inserted successfully.
// randomSet.insert(1);
//
// // Returns false as 2 does not exist in the set.
// randomSet.remove(2);
//
// // Inserts 2 to the set, returns true. Set now contains [1,2].
// randomSet.insert(2);
//
// // getRandom should return either 1 or 2 randomly.
// randomSet.getRandom();
//
// // Removes 1 from the set, returns true. Set now contains [2].
// randomSet.remove(1);
//
// // 2 was already in the set, so return false.
// randomSet.insert(2);
//
// // Since 2 is the only number in the set, getRandom always return 2.
// randomSet.getRandom();
//
//


class RandomizedSet {
private:
    unordered_set<int> us;
    default_random_engine generator;
    
    
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        us.clear();
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        auto it = us.find(val);
        if (it != us.end()) {
            return false;
        }
        else {
            us.insert(val);
            return true;
        }
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        auto it = us.find(val);
        if (it == us.end()) {
            return false;
        }
        else {
            us.erase(it);
            return true;
        }
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        int s = us.size();
        uniform_int_distribution<int> distribution(0, s - 1);
        int number = distribution(generator);
        auto it = us.begin();
        for (int i = 0; i < number; i++) it++;
        return *it;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet obj = new RandomizedSet();
 * bool param_1 = obj.insert(val);
 * bool param_2 = obj.remove(val);
 * int param_3 = obj.getRandom();
 */
