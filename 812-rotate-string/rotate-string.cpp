// We are given two strings, A and B.
//
// A shift on A consists of taking string A and moving the leftmost character to the rightmost position. For example, if A = 'abcde', then it will be 'bcdea' after one shift on A. Return True if and only if A can become B after some number of shifts on A.
//
//
// Example 1:
// Input: A = 'abcde', B = 'cdeab'
// Output: true
//
// Example 2:
// Input: A = 'abcde', B = 'abced'
// Output: false
//
//
// Note:
//
//
// 	A and B will have length at most 100.
//
//


class Solution {
public:
    bool rotateString(string A, string B) {
        if (A.size() != B.size()) return false;
        string aa = A + A;
        int pos = aa.find(B);
        if (pos == std::string::npos) return false;
        string ns = aa.substr(pos + B.size(), B.size() - pos) + aa.substr(0, pos);
        return ns == B;
    }
};
