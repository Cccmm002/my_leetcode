// Given two strings A and B, find the minimum number of times A has to be repeated such that B is a substring of it. If no such solution, return -1.
//
//
// For example, with A = "abcd" and B = "cdabcdab". 
//
//
// Return 3, because by repeating A three times (“abcdabcdabcd”), B is a substring of it; and B is not a substring of A repeated two times ("abcdabcd").
//
//
// Note:
// The length of A and B will be between 1 and 10000.


class Solution {
public:
    int repeatedStringMatch(string A, string B) {
        string s = A;
        int count = 1;
        while (s.size() < B.size()) {
            s = s + A;
            count += 1;
        }
        if (s.find(B) != string::npos) return count;
        s += A;
        count++;
        if (s.find(B) != string::npos) return count;
        else return -1;
    }
};
