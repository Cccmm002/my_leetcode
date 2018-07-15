// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.
//
//
// Example 1:
//
//
// Input: nums = [1,2,3,1], k = 3, t = 0
// Output: true
//
//
//
// Example 2:
//
//
// Input: nums = [1,0,1,1], k = 1, t = 2
// Output: true
//
//
//
// Example 3:
//
//
// Input: nums = [1,5,9,1,5,9], k = 2, t = 3
// Output: false
//
//
//
//
//


class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        int length = nums.size();
        if (length <= 1) return false;
        map<long long, vector<int>> tree;
        for (int i = 0; i < length; ++i) {
            auto it = tree.lower_bound((long long)nums[i] - (long long)t);
            if (it != tree.end()) {
                while (it != tree.end() && it->first <= (long long)nums[i] + (long long)t) {
                    if (i - it->second[it->second.size() - 1] <= k)
                        return true;
                    it++;
                }
            }
            auto find_it = tree.find((long long)nums[i]);
            if (find_it == tree.end()) {
                vector<int> v = {i};
                tree[(long long)nums[i]] = v;
            }
            else {
                find_it->second.push_back(i);
            }
        }
        return false;
    }
};
