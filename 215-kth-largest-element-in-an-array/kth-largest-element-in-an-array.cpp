// Find the kth largest element in an unsorted array. Note that it is the kth largest element in the sorted order, not the kth distinct element.
//
// For example,
// Given [3,2,1,5,6,4] and k = 2, return 5.
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ array's length.
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        make_heap(nums.begin(),nums.end());
        int top;
        for(int i=0;i<k;i++){
            pop_heap(nums.begin(),nums.end());
            top=nums[nums.size()-1];
            nums.pop_back();
        }
        return top;
    }
};