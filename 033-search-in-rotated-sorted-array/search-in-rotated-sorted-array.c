// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).
//
// You are given a target value to search. If found in the array return its index, otherwise return -1.
//
// You may assume no duplicate exists in the array.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// Example 1:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
//
//
// Example 2:
//
//
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1
//


int search(int* nums, int numsSize, int target) {
    int begin = 0;
    int end = numsSize;
    while (begin < end) {
        if (nums[begin] == target) return begin;
        if (nums[end-1] == target) return end-1;
        int mid = (end + begin)/2;
        if (nums[mid] == target)
            return mid;
        if (nums[mid] < target) {
            if (nums[end-1] > target) {  //right
                begin = mid + 1;
                continue;
            }
            else {
                if (nums[end-1] > nums[mid]) {  //left
                    end = mid;
                    continue;
                }
                else {  //right
                    begin = mid + 1;
                    continue;
                }
            }
        }
        else {
            if (nums[begin] < target) {  //left
                end = mid;
                continue;
            }
            else {
                if (nums[begin] > nums[mid]) {  //left
                    end = mid;
                    continue;
                }
                else {  //right
                    begin = mid + 1;
                    continue;
                }
            }
        }
    }
    return -1;
}
