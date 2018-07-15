// Given two integers n and k, return all possible combinations of k numbers out of 1 ... n.
//
// Example:
//
//
// Input: n = 4, k = 2
// Output:
// [
//   [2,4],
//   [3,4],
//   [2,3],
//   [1,2],
//   [1,3],
//   [1,4],
// ]
//
//


class Solution {
private:
    vector<vector<int>> gen(int k, int min, int max) {
        vector<vector<int>> res;
        if(min>max) return res;
        if(k==1){
            for(int i=min;i<=max;i++) {
                vector<int> v={i};
                res.push_back(v);
            }
            return res;
        }
        for(int i=min;i<=max;i++) {
            vector<vector<int>> last=gen(k-1,i+1,max);
            for(vector<int> v:last) {
                v.insert(v.begin(),i);
                res.push_back(v);
            }
        }
        return res;
    }
public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> empty;
        if(k==0){
            vector<vector<int>> v={empty};
            return v;
        }
        return gen(k,1,n);
    }
};
