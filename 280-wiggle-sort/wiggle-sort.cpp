// Given an unsorted array nums, reorder it in-place such that nums[0] <= nums[1] >= nums[2] <= nums[3]....
//
//
// For example, given nums = [3, 5, 2, 1, 6, 4], one possible answer is [1, 6, 2, 5, 3, 4].


class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return;
        sort(nums.begin(), nums.end());
        vector<int> v(nums);
        int mid = (len - 1)/2;
        for (int i = 0; i <= mid; i++) {
            nums[i*2] = v[i];
        }
        for (int i = mid + 1; i < len; i++) {
            int j = i - mid - 1;
            nums[2*j + 1] = v[i];
        }
    }
};
