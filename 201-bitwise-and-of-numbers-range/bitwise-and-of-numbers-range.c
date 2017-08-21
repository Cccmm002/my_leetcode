// Given a range [m, n] where 0 <= m <= n <= 2147483647, return the bitwise AND of all numbers in this range, inclusive.
//
//
// For example, given the range [5, 7], you should return 4.
//
//
// Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.


int rangeBitwiseAnd(int m, int n) {
    if (m == 0) return 0;
    int mask = 1;
    while (m != n) {
        m = m >> 1;
        n = n >> 1;
        mask = mask << 1;
    }
    return m * mask;
}
