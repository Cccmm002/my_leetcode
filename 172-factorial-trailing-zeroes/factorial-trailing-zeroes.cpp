// Given an integer n, return the number of trailing zeroes in n!.
//
// Note: Your solution should be in logarithmic time complexity.
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int trailingZeroes(int n) {
        int res = 0;
        for (long long i = 5; true; i *= 5) {
            int t = n / i;
            if (t == 0) break;
            res += t;
        }
        return res;
    }
};
