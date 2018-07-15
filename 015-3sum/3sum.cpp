// Given an array nums of n integers, are there elements a, b, c in nums such that a + b + c = 0? Find all unique triplets in the array which gives the sum of zero.
//
// Note:
//
// The solution set must not contain duplicate triplets.
//
// Example:
//
//
// Given array nums = [-1, 0, 1, 2, -1, -4],
//
// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]
//
//


class Solution {
public:
vector<vector<int>> threeSum(vector<int>& nums) {
    int length=nums.size();
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i=0;i<length;i++){
        if(i!=0)
            if(nums[i]==nums[i-1])
                continue;
        if(nums[i]>0)
            break;
        int twoSum=0-nums[i];
        int begin=i+1,end=length-1;
        while(begin<end){
            int s=nums[begin]+nums[end];
            if(twoSum==s){
                vector<int> v;
                v.push_back(nums[i]);
                v.push_back(nums[begin]);
                v.push_back(nums[end]);
                res.push_back(v);
                begin++;
                while(begin<end && nums[begin]==nums[begin-1])
                    begin++;
            }
            else if(twoSum<s)
                end--;
            else
                begin++;
        }
    }
    return res;
}
};
