// Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
// Each element in the array represents your maximum jump length at that position.
//
// Your goal is to reach the last index in the minimum number of jumps.
//
// Example:
//
//
// Input: [2,3,1,1,4]
// Output: 2
// Explanation: The minimum number of jumps to reach the last index is 2.
//     Jump 1 step from index 0 to 1, then 3 steps to the last index.
//
// Note:
//
// You can assume that you can always reach the last index.


class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return 0;
        int p = 0, currentMax = 0, level = 0;
        while (p < n) {
            ++level;
            int nextMax = currentMax;
            while (p <= currentMax) {
                nextMax = max(nextMax, p + nums[p]);
                ++p;
                if (nextMax >= n - 1) return level;
            }
            currentMax = nextMax;
        }
        return -1;
    }
};
