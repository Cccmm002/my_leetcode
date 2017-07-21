// Given an array which consists of non-negative integers and an integer m, you can split the array into m non-empty continuous subarrays. Write an algorithm to minimize the largest sum among these m subarrays.
//
//
// Note:
// If n is the length of array, assume the following constraints are satisfied:
//
// 1 &le; n &le; 1000
// 1 &le; m &le; min(50, n)
//
//
//
// Examples: 
//
// Input:
// nums = [7,2,5,10,8]
// m = 2
//
// Output:
// 18
//
// Explanation:
// There are four ways to split nums into two subarrays.
// The best way is to split it into [7,2,5] and [10,8],
// where the largest sum among the two subarrays is only 18.


class Solution {
public:
    int splitArray(vector<int>& nums, int m) {
        int len = nums.size();
        vector<vector<long long>> arr(len);
        for (int i = 0; i < len; i++) {
            arr[i] = vector<long long>(m);
        }
        arr[0][0] = nums[0];
        for (int i = 1; i < m; i++) arr[0][i] = LLONG_MIN;
        for (int i = 1; i < len; i++) arr[i][0] = arr[i - 1][0] + nums[i];
        for (int j = 1; j < m; j++) {
            for (int i = 1; i < len; i++) {
                long long smallest = LLONG_MAX;
                for (int k = 0; k <= i; k++) {
                    long long a = arr[i - k][j - 1];
                    long long b = arr[i][0] - arr[i - k][0];
                    long long r = a > b ? a : b;
                    smallest = r < smallest ? r : smallest;
                }
                arr[i][j] = smallest;
            }
        }
        return arr[len - 1][m - 1];
    }
};
