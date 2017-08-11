// Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
//
//
// For example,
// Given [100, 4, 200, 1, 3, 2],
// The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
//
//
// Your algorithm should run in O(n) complexity.


class UF {
private:
    unordered_map<int, int> ump;
    
public:
    UF(vector<int>& nums) {
        for (int n : nums) {
            ump[n] = n;
        }
    }
    
    inline bool exist(int n) {
        return ump.find(n) != ump.end();
    }
    
    int find(int n) {
        if (n == ump[n]) return n;
        int parent = find(ump[n]);
        ump[n] = parent;
        return parent;
    }
    
    inline void merge(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA != rootB) 
            ump[a] = rootB;
    }
    
    int longest(unordered_set<int>& nums) {
        unordered_map<int, int> buckets;
        for (int n : nums) {
            int b = find(n);
            if (buckets.find(b) == buckets.end()) buckets[b] = 1;
            else buckets[b] += 1;
        }
        auto it = buckets.begin();
        int res = 0;
        while (it != buckets.end()) {
            res = max(res, it->second);
            it++;
        }
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        UF *uf = new UF(nums);
        for (int n : nums) {
            if (uf->exist(n - 1)) uf->merge(n, n - 1);
            if (uf->exist(n + 1)) uf->merge(n, n + 1);
        }
        unordered_set<int> s;
        for (int n : nums) s.insert(n);
        int res = uf->longest(s);
        delete uf;
        return res;
    }
};
