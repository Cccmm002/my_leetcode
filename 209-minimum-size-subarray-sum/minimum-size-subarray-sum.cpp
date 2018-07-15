// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
//
// Example: 
//
//
// Input: s = 7, nums = [2,3,1,2,4,3]
// Output: 2
// Explanation: the subarray [4,3] has the minimal length under the problem constraint.
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
//


class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size();
        if (n == 0) return 0;
        int a = 0, b = 0;
        int sum = nums[0];
        int res = INT_MAX;
        while (a < n) {
            while (b < n) {
                if (sum >= s) {
                    res = min(res, b - a + 1);
                    break;
                }
                ++b;
                sum += nums[b];
            }
            sum -= nums[a];
            ++a;
        }
        if (res == INT_MAX) return 0;
        else return res;
    }
};
