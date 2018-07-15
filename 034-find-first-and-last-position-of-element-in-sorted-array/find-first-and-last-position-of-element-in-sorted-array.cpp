// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2, -1);
        int n = nums.size();
        if (n == 0) return res;
        int l = 0, r = n - 1;
        while (l < r) {
            int m = (l + r)/2;
            if (nums[m] < target) l = m + 1;
            else r = m;
        }
        if (nums[l] != target) return res;
        res[0] = l;
        r = n - 1;
        while (l < r) {
            int m = (l + r)/2 + 1;
            if (nums[m] <= target) l = m;
            else r = m - 1;
        }
        res[1] = r;
        return res;
    }
};
