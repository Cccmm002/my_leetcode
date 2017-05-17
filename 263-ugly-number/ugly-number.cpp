// Write a program to check whether a given number is an ugly number.
//
//
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5. For example, 6, 8 are ugly while 14 is not ugly since it includes another prime factor 7.
//
//
//
// Note that 1 is typically treated as an ugly number.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    bool ugly(int num, unordered_map<int,bool> &m){
        if(num==1) return true;
        if(num==0) return false;
        auto it=m.find(num);
        if(it!=m.end()) return it->second;
        bool res=false;
        if(num%3==0) res=ugly(num/3, m);
        else if(num%5==0) res=ugly(num/5,m);
        else if(num%2==0) res=ugly(num/2,m);
        else res=false;
        m[num]=res;
        return res;
    }

    bool isUgly(int num) {
        unordered_map<int,bool> m;
        return ugly(num,m);
    }
};
