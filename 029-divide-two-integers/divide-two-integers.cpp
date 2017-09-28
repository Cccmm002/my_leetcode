// Divide two integers without using multiplication, division and mod operator.
//
//
// If it is overflow, return MAX_INT.


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

