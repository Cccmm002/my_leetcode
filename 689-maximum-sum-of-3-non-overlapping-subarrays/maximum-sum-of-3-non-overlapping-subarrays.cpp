// In a given array nums of positive integers, find three non-overlapping subarrays with maximum sum.
//
//
// Each subarray will be of size k, and we want to maximize the sum of all 3*k entries.
//
//
// Return the result as a list of indices representing the starting position of each interval (0-indexed).  If there are multiple answers, return the lexicographically smallest one.
//
// Example:
//
// Input: [1,2,1,2,6,7,5,1], 2
// Output: [0, 3, 5]
// Explanation: Subarrays [1, 2], [2, 6], [7, 5] correspond to the starting indices [0, 3, 5].
// We could have also taken [2, 1], but an answer of [1, 3, 5] would be lexicographically larger.
//
//
//
// Note:
// nums.length will be between 1 and 20000.
// nums[i] will be between 1 and 65535.
// k will be between 1 and floor(nums.length / 3).


class Solution {
public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int len = nums.size();
        vector<vector<int>> arr(len);
        vector<vector<int>> rl(len);
        for (int i = 0; i < len; i++) {
            vector<int> v(4, 0);
            vector<int> vrl(4, 0);
            arr[i] = v;
            rl[i] = vrl;
        }
        for (int j = 1; j < 4; j++) {
            for (int i = 0; i < len; i++) {
                if (i < j*k - 1) continue;
                int a = (i - 1) < 0 ? 0 : arr[i - 1][j];
                int b = (i - k) < 0 ? 0 : arr[i - k][j - 1];
                for (int s = i - k + 1; s < i + 1; s++)
                    b += nums[s];
                if (b > a) {
                    arr[i][j] = b;
                    rl[i][j] = i - k;
                }
                else {
                    arr[i][j] = a;
                    rl[i][j] = rl[i - 1][j];
                }
            }
        }
        vector<int> res(3);
        res[2] = rl[len - 1][3];
        res[1] = rl[res[2]][2];
        res[0] = rl[res[1]][1];
        for (int i = 0; i < 3; i++) res[i] = res[i] + 1;
        return res;
    }
};
