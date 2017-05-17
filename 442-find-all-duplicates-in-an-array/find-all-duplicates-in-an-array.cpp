// Given an array of integers, 1 &le; a[i] &le; n (n = size of array), some elements appear twice and others appear once.
//
// Find all the elements that appear twice in this array.
//
// Could you do it without extra space and in O(n) runtime?
//
// Example:
//
// Input:
// [4,3,2,7,8,2,3,1]
//
// Output:
// [2,3]


class Solution {
private:
    inline int abs(int n) {
        return n>0?n:(0-n);
    }
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int len=nums.size();
        vector<int> res;
        for(int i=0;i<len;i++) {
            int cur=abs(nums[i])-1;
            if(nums[cur]<0)
                res.push_back(cur+1);
            else
                nums[cur]=0-nums[cur];
        }
        return res;
    }
};
