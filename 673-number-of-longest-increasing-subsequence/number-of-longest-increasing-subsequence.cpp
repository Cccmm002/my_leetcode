// Given an unsorted array of integers, find the number of longest increasing subsequence.
//
//
// Example 1:
//
// Input: [1,3,5,4,7]
// Output: 2
// Explanation: The two longest increasing subsequence are [1, 3, 4, 7] and [1, 3, 5, 7].
//
//
//
// Example 2:
//
// Input: [2,2,2,2,2]
// Output: 5
// Explanation: The length of longest continuous increasing subsequence is 1, and there are 5 subsequences' length is 1, so output 5.
//
//
//
// Note:
// Length of the given array will be not exceed 2000 and the answer is guaranteed to be fit in 32-bit signed int.


class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 1);
        vector<int> count(n, 1);
        for (int i = 1; i < n; i++) {
            int cur = 1;
            int cur_count = 1;
            for (int j = 0; j < i; j++) {
                if (nums[j] >= nums[i]) continue;
                if (arr[j] + 1 == cur) {
                    cur_count += count[j];
                }
                else if (arr[j] + 1 > cur) {
                    cur = arr[j] + 1;
                    cur_count = count[j];
                }
            }
            arr[i] = cur;
            count[i] = cur_count;
        }
        int res = 0;
        int m = 0;
        for (int i = 0; i < n; i++) {
            if (m == arr[i]) res += count[i];
            else if(arr[i] > m) {
                res = count[i];
                m = arr[i];
            }
        }
        return res;
    }
};
