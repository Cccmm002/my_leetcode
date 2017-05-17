// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
//
//
// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//
//
// Note: You may assume that n is not less than 2 and not larger than 58.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    int helper(int n, map<int,int> &m) {
        if(n==2) return 2;
        if(n==3) return 3;
        if(n==4) return 4;
        if(n==5) return 6;
        auto it=m.find(n);
        if(it!=m.end()) return it->second;
        int three=helper(n-3,m)*3;
        int four=helper(n-4,m)*4;
        int res=three>four?three:four;
        m[n]=res;
        return res;
    }
    
    int integerBreak(int n) {
        if(n==2) return 1;
        if(n==3) return 2;
        map<int,int> m;
        return helper(n,m);
    }
};
