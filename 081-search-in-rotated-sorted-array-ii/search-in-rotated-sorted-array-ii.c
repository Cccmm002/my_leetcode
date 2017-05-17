// Follow up for "Search in Rotated Sorted Array":
// What if duplicates are allowed?
//
// Would this affect the run-time complexity? How and why?
//
//
// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// Write a function to determine if a given target is in the array.
//
// The array may contain duplicates.


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
