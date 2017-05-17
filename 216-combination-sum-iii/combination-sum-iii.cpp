// Find all possible combinations of k numbers that add up to a number n, given that only numbers from 1 to 9 can be used and each combination should be a unique set of numbers.
//
//
//
//  Example 1:
// Input:  k = 3,  n = 7
// Output: 
//
// [[1,2,4]]
//
//
//  Example 2:
// Input:  k = 3,  n = 9
// Output: 
//
// [[1,2,6], [1,3,5], [2,3,4]]
//
//
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
private:
    vector<vector<int>> sum(int k, int n, int starter) {
        vector<vector<int>> res;
        res.clear();
        if(k<=0) return res;
        if(n==0) return res;
        if(n<starter) return res;
        if(k==1 && n<10){
            vector<int> v={n};
            res.push_back(v);
            return res;
        } 
        for(int i=starter;i<10;i++){
            if(i>n) break;
            vector<vector<int>> vv=sum(k-1,n-i,i+1);
            for(vector<int> v:vv){
                v.insert(v.begin(),i);
                res.push_back(v);
            }
        }
        return res;
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        return sum(k,n,1);
    }
};
