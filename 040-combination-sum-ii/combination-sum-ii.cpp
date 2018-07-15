// Given a collection of candidate numbers (candidates) and a target number (target), find all unique combinations in candidates where the candidate numbers sums to target.
//
// Each number in candidates may only be used once in the combination.
//
// Note:
//
//
// 	All numbers (including target) will be positive integers.
// 	The solution set must not contain duplicate combinations.
//
//
// Example 1:
//
//
// Input: candidates = [10,1,2,7,6,1,5], target = 8,
// A solution set is:
// [
//   [1, 7],
//   [1, 2, 5],
//   [2, 6],
//   [1, 1, 6]
// ]
//
//
// Example 2:
//
//
// Input: candidates = [2,5,2,1,2], target = 5,
// A solution set is:
// [
//   [1,2,2],
//   [5]
// ]
//
//


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
