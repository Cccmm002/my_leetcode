// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
// Given a non-empty string containing only digits, determine the total number of ways to decode it.
//
// Example 1:
//
//
// Input: "12"
// Output: 2
// Explanation: It could be decoded as "AB" (1 2) or "L" (12).
//
//
// Example 2:
//
//
// Input: "226"
// Output: 3
// Explanation: It could be decoded as "BZ" (2 26), "VF" (22 6), or "BBF" (2 2 6).
//


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
