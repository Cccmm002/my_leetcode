// Given an unsorted array nums, reorder it such that
//     nums[0] < nums[1] > nums[2] < nums[3]....
//
//
//
//     Example:
//     (1) Given nums = [1, 5, 1, 1, 6, 4], one possible answer is [1, 4, 1, 5, 1, 6]. 
//     (2) Given nums = [1, 3, 2, 2, 3, 1], one possible answer is [2, 3, 1, 3, 1, 2].
//
//
//
//     Note:
//     You may assume all input has valid answer.
//
//
//
//     Follow Up:
//     Can you do it in O(n) time and/or in-place with O(1) extra space?
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
private:
    void quickselect(vector<int>& nums, int begin, int end, int k) {
        if (begin >= end) return;
        int pivot = nums[end];
        int s = begin;
        for (int p = begin; p < end; ++p) {
            if (nums[p] < pivot) {
                std::swap(nums[s], nums[p]);
                ++s;
            }
        }
        std::swap(nums[s], nums[end]);
        if (s + 1 == k) return;
        else if (s + 1 < k) return quickselect(nums, s + 1, end, k);
        else return quickselect(nums, begin, s - 1, k);
    }
    
    inline int newIndex(int index, int n) {
        return (1 + 2*index) % (n | 1);
    }
    
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        int m = (len + 1) / 2;
        quickselect(nums, 0, len - 1, m);
        int median = nums[m - 1];

        int left = 0, i = 0, right = len - 1;

        while (i <= right) {
            if (nums[newIndex(i, len)] > median) {
                swap(nums[newIndex(left++, len)], nums[newIndex(i++, len)]);
            }
            else if (nums[newIndex(i, len)] < median) {
                swap(nums[newIndex(right--, len)], nums[newIndex(i, len)]);
            }
            else {
                i++;
            }
        }
    }
};
