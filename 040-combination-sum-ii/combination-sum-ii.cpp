// Given a collection of candidate numbers (C) and a target number (T), find all unique combinations in C where the candidate numbers sums to T.
//
//
// Each number in C may only be used once in the combination.
//
// Note:
//
// All numbers (including target) will be positive integers.
// The solution set must not contain duplicate combinations.
//
//
//
//
// For example, given candidate set [10, 1, 2, 7, 6, 1, 5] and target 8, 
// A solution set is: 
//
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
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
            if(it!=begin && *it==*(it-1)) {it++; continue;}
            if(target-*it==0){
                vector<int> vv={target};
                res.push_back(vv);
            }
            else {
                vector<vector<int>> s=summer(it+1,end,target-*it);
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
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        return summer(candidates.begin(),candidates.end(),target);
    }
};
