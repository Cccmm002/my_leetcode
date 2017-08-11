// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
//
// Given an encoded message containing digits, determine the total number of ways to decode it.
//
//
//
// For example,
// Given encoded message "12",
// it could be decoded as "AB" (1 2) or "L" (12).
//
//
//
// The number of ways decoding "12" is 2.


class Solution {
public:
    int numDecodings(string s) {
        int n = s.size();
        if (n == 0) return 0;
        vector<int> v(n, 0);
        v[0] = s[0] == '0' ? 0 : 1;
        for (int i = 1; i < n; i++) {
            if (s[i] != '0') v[i] += v[i - 1];
            if (s[i - 1] == '0') continue;
            int two = stoi(s.substr(i - 1, 2));
            if (two >= 1 && two <= 26) {
                if (i - 2 >= 0)
                    v[i] += v[i - 2];
                else
                    v[i] += 1;
            }
        }
        return v[n - 1];
    }
};
