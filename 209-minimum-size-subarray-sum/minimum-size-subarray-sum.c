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


inline int min(int a, int b) {
    return a < b ? a : b;
}

int minSubArrayLen(int s, int* nums, int numsSize) {
    if (numsSize <= 0) return 0;
    int beg = 0;
    int end = 0;
    int res = 2147483647;
    int curSum = nums[0];
    while (end < numsSize) {
        if (curSum < s) {
            end++;
            if (end < numsSize)
                curSum += nums[end];
        }
        else {
            res = min(res, end - beg + 1);
            curSum -= nums[beg];
            beg++;
        }
    }
    if (res == 2147483647) return 0;
    else return res;
}
