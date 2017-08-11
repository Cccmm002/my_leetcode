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
