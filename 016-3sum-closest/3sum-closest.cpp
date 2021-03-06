// Given an array nums of n integers and an integer target, find three integers in nums such that the sum is closest to target. Return the sum of the three integers. You may assume that each input would have exactly one solution.
//
// Example:
//
//
// Given array nums = [-1, 2, 1, -4], and target = 1.
//
// The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).
//
//


class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        int diff = INT_MAX;
        for (int i = 0; i < n; i++) {
            int j = i + 1;
            int k = n - 1;
            while (j < k) {
                int cur = nums[i] + nums[j] + nums[k];
                int d = abs(target - cur);
                if (d < diff) {
                    diff = d;
                    res = cur;
                }
                if (cur == target)
                    return target;
                else if (cur < target)
                    j++;
                else
                    k--;
            }
        }
        return res;
    }
};
