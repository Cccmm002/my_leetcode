// Given an integer, return its base 7 string representation.
//
// Example 1:
//
// Input: 100
// Output: "202"
//
//
//
// Example 2:
//
// Input: -7
// Output: "-10"
//
//
//
// Note:
// The input will be in range of [-1e7, 1e7].
//


class Solution {
public:
    string convertToBase7(int num) {
        if (num == 0) return "0";
        string res = "";
        bool positive = num >= 0;
        if (!positive) num = 0 - num;
        while (num > 0) {
            char c = '0' + (num%7);
            res = c + res;
            num = num/7;
        }
        if (!positive) res = '-' + res;
        return res;
    }
};
