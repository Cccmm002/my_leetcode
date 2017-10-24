// Given a collection of integers that might contain duplicates, nums, return all possible subsets (the power set).
//
// Note: The solution set must not contain duplicate subsets.
//
//
// For example,
// If nums = [1,2,2], a solution is:
//
//
//
// [
//   [2],
//   [1],
//   [1,2,2],
//   [2,2],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> empty;
        int len=nums.size();
        if(len==0) {
            res.push_back(empty);
            return res;
        }
        if(len==1) {
            res.push_back(empty);
            vector<int> single={nums[0]};
            res.push_back(single);
            return res;
        }
        sort(nums.begin(),nums.end());
        
        int repeatTimes=1;
        while(repeatTimes<len && nums[0]==nums[repeatTimes])
            repeatTimes++;
        
        vector<int> v(nums.begin()+repeatTimes,nums.end());
        vector<vector<int>> last=subsetsWithDup(v);
        int lastSize=last.size();
        
        res.push_back(empty);
        for(int i=1;i<=repeatTimes;i++){
            vector<int> v;
            for(int j=0;j<i;j++) 
                v.push_back(nums[0]);
            res.push_back(v);
        }
        for(int i=repeatTimes;i>=0;i--){
            vector<int> v;
            for(int j=0;j<i;j++) 
                v.push_back(nums[0]);
            for(int j=1;j<lastSize;j++){
                vector<int> v2(v);
                vector<int> v_ori=last[j];
                for(int k=0;k<v_ori.size();k++)
                    v2.push_back(v_ori[k]);
                res.push_back(v2);
            }
        }
        
        return res;
    }
};
