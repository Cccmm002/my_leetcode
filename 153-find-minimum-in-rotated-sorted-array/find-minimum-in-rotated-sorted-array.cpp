// Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.
//
// (i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).
//
// Find the minimum element.
//
// You may assume no duplicate exists in the array.


class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return nums[0];
        int beg = 0, end = n - 1;
        while (beg < end - 1) {
            if (nums[beg] < nums[end])
                return nums[beg];
            int mid = (beg + end)/2;
            if (nums[mid] > nums[end])
                beg = mid;
            else
                end = mid;
        }
        return min(nums[beg], nums[end]);
    }
};
