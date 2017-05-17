// Follow up for "Find Minimum in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// Find the minimum element.
//
// The array may contain duplicates.


int findMin(int* nums, int numsSize) {
    if (numsSize == 1) return nums[0];
    int begin = 0;
    int end = numsSize - 1;
    while (begin <= end) {
        if (nums[begin] < nums[end])
            return nums[begin];
        if (begin + 1 == end) {
            return nums[begin] < nums[end] ? nums[begin] : nums[end];
        }
        int mid = (begin + end) >> 1;
        if (nums[mid] > nums[begin]) {
            begin = mid;
            continue;
        }
        else if (nums[mid] < nums[begin]){
            end = mid;
            continue;
        }
        else {
            begin++;
        }
    }
    return 0;
}
