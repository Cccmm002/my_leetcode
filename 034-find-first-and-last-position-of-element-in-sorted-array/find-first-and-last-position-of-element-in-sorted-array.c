// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* searchRange(int* nums, int numsSize, int target, int* returnSize) {
    *returnSize = 2;
    int *res = (int*)malloc(sizeof(int)*2);
    int left = -1, right = numsSize;
    while (right - left > 1) {
        int mid = left + (right - left)/2;
        if (nums[mid] < target) left = mid;
        else right = mid;
    }
    res[0] = (right < numsSize && nums[right] == target) ? right : -1;
    left = -1; right = numsSize;
    while (right - left > 1) {
        int mid = left + (right - left)/2;
        if (nums[mid] <= target) left = mid;
        else right = mid;
    }
    res[1] = (left >= 0 && nums[left] == target) ? left : -1;
    return res;
}
