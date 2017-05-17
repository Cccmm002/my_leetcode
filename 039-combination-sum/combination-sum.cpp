// Given a set of candidate numbers (C) (without duplicates) and a target number (T), find all unique combinations in C where the candidate numbers sums to T. 
//
//
// The same repeated number may be chosen from C unlimited number of times.
//
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
//
//
//
// For example, given candidate set [2, 3, 6, 7] and target 7, 
// A solution set is: 
//
// [
//   [7],
//   [2, 2, 3]
// ]


class Solution {
private:
    vector<vector<int>> summer(vector<int>::iterator begin, vector<int>::iterator end, int target) {
        vector<vector<int>> res;
        res.clear();
        if(target<=0) return res;
        vector<int>::iterator it=begin;
        while(it!=end) {
            if(*it>target) break;
            if(target-*it==0){
                vector<int> vv={target};
                res.push_back(vv);
            }
            else {
                vector<vector<int>> s=summer(it,end,target-*it);
                for(vector<int> v:s) {
                    v.insert(v.begin(),*it);
                    res.push_back(v);
                }
            }
            it++;
        }
        return res;
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return summer(candidates.begin(),candidates.end(),target);
    }
};
