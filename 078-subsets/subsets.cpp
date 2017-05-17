// Given a set of distinct integers, nums, return all possible subsets.
//
// Note: The solution set must not contain duplicate subsets.
//
//
// For example,
// If nums = [1,2,3], a solution is:
//
//
//
// [
//   [3],
//   [1],
//   [2],
//   [1,2,3],
//   [1,3],
//   [2,3],
//   [1,2],
//   []
// ]


class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
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
        vector<int> v(nums.begin(),nums.end()-1);
        vector<vector<int>> last=subsets(v);
        int size=last.size();
        for(int i=0;i<size;i++)
            res.push_back(last[i]);
        for(int i=0;i<size;i++){
            vector<int> cur=last[i];
            cur.push_back(*(nums.end()-1));
            res.push_back(cur);
        }
        return res;
    }
};
