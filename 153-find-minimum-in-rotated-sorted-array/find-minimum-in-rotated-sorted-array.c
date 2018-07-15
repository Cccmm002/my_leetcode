// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e.,  [0,1,2,4,5,6,7] might become  [4,5,6,7,0,1,2]).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.
//
// Example 1:
//
//
// Input: [3,4,5,1,2] 
// Output: 1
//
//
// Example 2:
//
//
// Input: [4,5,6,7,0,1,2]
// Output: 0
//
//


int findMin(int* nums, int numsSize) {
    int begin = 0;
    int end = numsSize - 1;
    while (begin <= end) {
        if (nums[begin] <= nums[end])
            return nums[begin];
        if (begin + 1 == end) {
            return nums[begin] < nums[end] ? nums[begin] : nums[end];
        }
        int mid = (begin + end) >> 1;
        if (nums[mid] > nums[begin]) {
            begin = mid;
            continue;
        }
        else {
            end = mid;
            continue;
        }
    }
    return 0;
}
