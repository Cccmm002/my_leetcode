// Given a collection of distinct numbers, return all possible permutations.
//
//
//
// For example,
// [1,2,3] have the following permutations:
//
// [
//   [1,2,3],
//   [1,3,2],
//   [2,1,3],
//   [2,3,1],
//   [3,1,2],
//   [3,2,1]
// ]


class Solution {
public:
    vector<vector<int>> _permute(vector<int>& nums) {
        vector<vector<int>> res;
        res.clear();
        int size=nums.size();
        if(size==0) return res;
        if(size==1){
            vector<int> v={nums[0]};
            res.push_back(v);
            return res;
        }
        for(int i=0;i<size;i++){
            vector<int> new_nums=nums;
            new_nums.erase(new_nums.begin()+i);
            vector<vector<int>> vvi=_permute(new_nums);
            for(auto v:vvi){
                v.push_back(nums[i]);
                res.push_back(v);
            }
        }
        return res;
    }
    
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> vvi=_permute(nums);
        vector<vector<int>> res;
        res.clear();
        for(auto v:vvi){
            vector<int> vr;
            for(int i=v.size()-1;i>=0;i--)
                vr.push_back(v[i]);
            res.push_back(vr);
        }
        return res;
    }
};
