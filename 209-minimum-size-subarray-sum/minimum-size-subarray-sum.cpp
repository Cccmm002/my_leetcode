// Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum &ge; s. If there isn't one, return 0 instead.
//
//
// For example, given the array [2,3,1,2,4,3] and s = 7,
// the subarray [4,3] has the minimal length under the problem constraint.
//
//
// click to show more practice.
//
// More practice:
//
// If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n).
//
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


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
