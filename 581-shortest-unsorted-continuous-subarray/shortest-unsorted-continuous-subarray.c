// Given an integer array, you need to find one continuous subarray that if you only sort this subarray in ascending order, then the whole array will be sorted in ascending order, too.  
//
// You need to find the shortest such subarray and output its length.
//
// Example 1:
//
// Input: [2, 6, 4, 8, 10, 9, 15]
// Output: 5
// Explanation: You need to sort [6, 4, 8, 10, 9] in ascending order to make the whole array sorted in ascending order.
//
//
//
// Note:
//
// Then length of the input array is in range [1, 10,000].
// The input array may contain duplicates, so ascending order here means <=.


int findUnsortedSubarray(int* nums, int numsSize) {
    if (numsSize == 0) return 0;
    int b = 0;
    while (nums[b] <= nums[b + 1]) {
        b++;
        if (b >= numsSize - 1) return 0;
    }
    int e = numsSize - 1;
    while (nums[e] >= nums[e - 1]) {
        e--;
        if (e <= 0) break;
    }
    int large = INT_MIN;
    int small = INT_MAX;
    for (int i = b; i <= e; i++) {
        if (large < nums[i]) large = nums[i];
        if (small > nums[i]) small = nums[i];
    }
    for (int i = 0; i < b; i++) {
        if (small < nums[i]) {
            b = i;
            break;
        }
    }
    for (int i = numsSize - 1; i > e; i--) {
        if (large > nums[i]) {
            e = i;
            break;
        }
    }
    return e - b + 1;
}
