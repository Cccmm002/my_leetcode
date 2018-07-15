// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., [0,0,1,2,2,5,6] might become [2,5,6,0,0,1,2]).
//
// You are given a target value to search. If found in the array return true, otherwise return false.
//
// Example 1:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 0
// Output: true
//
//
// Example 2:
//
//
// Input: nums = [2,5,6,0,0,1,2], target = 3
// Output: false
//
// Follow up:
//
//
// 	This is a follow up problem to Search in Rotated Sorted Array, where nums may contain duplicates.
// 	Would this affect the run-time complexity? How and why?
//
//


bool search(int* nums, int numsSize, int target) {
    int begin = 0;
    int end = numsSize;
    while (begin < end) {
        int mid = (end + begin)/2;
        if (nums[mid] == target)
            return true;
        while (nums[mid] == nums[begin] && nums[mid] == nums[end-1]) {
            begin++;
            end--;
        }
        if (begin >= end) break;
        if (nums[begin] == target) return true;
        if (nums[end-1] == target) return true;
        if (nums[mid] < target) {
            if (nums[end-1] > target) {  //right
                begin = mid + 1;
                continue;
            }
            else {
                if (nums[end-1] >= nums[mid]) {  //left
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
    return false;
}
