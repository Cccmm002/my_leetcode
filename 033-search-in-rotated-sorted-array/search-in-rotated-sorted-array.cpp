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


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0) return -1;
        if (n == 1) {
            if (nums[0] == target) return 0;
            else return -1;
        }
        int left = 0, right = n - 1;
        while (left + 1 <= right) {
            //cout<<left<<" "<<right<<endl;
            if (nums[left] == target) return left;
            else if (nums[right] == target) return right;
            if (left + 1 == right) return -1;
            int mid = left + (right - left)/2;
            if (nums[mid] == target) return mid;
            if (nums[left] < target && target < nums[mid])
                right = mid;
            else if (nums[mid] < target && target < nums[right])
                left = mid;
            else if (nums[mid] > nums[right] && (target < nums[right] || target > nums[mid]))
                left = mid;
            else if (nums[left] > nums[mid] && (target < nums[mid] || target > nums[left]))
                right = mid;
            else
                return -1;
        }
        return -1;
    }
};
