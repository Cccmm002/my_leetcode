// Write a program to check whether a given number is an ugly number.
//
// Ugly numbers are positive numbers whose prime factors only include 2, 3, 5.
//
// Example 1:
//
//
// Input: 6
// Output: true
// Explanation: 6 = 2 × 3
//
// Example 2:
//
//
// Input: 8
// Output: true
// Explanation: 8 = 2 × 2 × 2
//
//
// Example 3:
//
//
// Input: 14
// Output: false 
// Explanation: 14 is not ugly since it includes another prime factor 7.
//
//
// Note:
//
//
// 	1 is typically treated as an ugly number.
// 	Input is within the 32-bit signed integer range: [−231,  231 − 1].
//
//


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
