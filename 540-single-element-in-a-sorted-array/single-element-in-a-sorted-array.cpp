// Given a sorted array consisting of only integers where every element appears twice except for one element which appears once. Find this single element that appears only once. 
//
//
// Example 1:
//
// Input: [1,1,2,3,3,4,4,8,8]
// Output: 2
//
//
//
// Example 2:
//
// Input: [3,3,7,7,10,11,11]
// Output: 10
//
//
//
// Note:
// Your solution should run in O(log n) time and O(1) space.


class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int beg = 0;
        int end = n - 1;
        while (end > beg) {
            int mid = (beg + end) / 2;
            if ((mid - beg) % 2 == 1) {
                if (nums[mid] != nums[mid - 1]) end = mid - 1;
                else beg = mid + 1;
            }
            else {
                if (nums[mid] != nums[mid - 1]) beg = mid;
                else end = mid;
            }
        }
        return nums[beg];
    }
};
