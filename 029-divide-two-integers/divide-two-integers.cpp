// Given two integers dividend and divisor, divide two integers without using multiplication, division and mod operator.
//
// Return the quotient after dividing dividend by divisor.
//
// The integer division should truncate toward zero.
//
// Example 1:
//
//
// Input: dividend = 10, divisor = 3
// Output: 3
//
// Example 2:
//
//
// Input: dividend = 7, divisor = -3
// Output: -2
//
// Note:
//
//
// 	Both dividend and divisor will be 32-bit signed integers.
// 	The divisor will never be 0.
// 	Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231,  231 − 1]. For the purpose of this problem, assume that your function returns 231 − 1 when the division result overflows.
//
//


class Solution {
public:
    int divide(int dividend, int divisor) {
        bool neg = (dividend > 0) != (divisor > 0);
        long long _dividend = dividend;
        long long _divisor = divisor;
        long long __dividend = (_dividend >= 0) ? _dividend : (0 - _dividend);
        long long __divisor = (_divisor >= 0) ? _divisor : (0 - _divisor);
        long long d = __dividend;
        long long res = 0;
        while (d >= __divisor) {
            long long cur = __divisor;
            long long mask = 1;
            while ((d - cur) >= 0) {
                cur = cur << 1;
                mask = mask << 1;
            }
            res += (mask >> 1);
            d -= (cur >> 1);
        }
        if (neg) res = 0 - res;
        if (res > INT_MAX) return INT_MAX;
        else return res;
    }
};

