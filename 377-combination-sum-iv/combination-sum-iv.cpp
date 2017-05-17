// Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


class Solution {
private:
    int sumCount(vector<int>& nums, int target, map<int,int> &m){
        if(target<0) return 0;
        if(target==0) return 1;
        auto it=m.find(target);
        if(it!=m.end()) return it->second;
        int res=0;
        for(int i:nums){
            res+=sumCount(nums,target-i,m);
        }
        m[target]=res;
        return res;
    }
public:
    int combinationSum4(vector<int>& nums, int target) {
        map<int,int> m;
        return sumCount(nums,target,m);
    }
};
