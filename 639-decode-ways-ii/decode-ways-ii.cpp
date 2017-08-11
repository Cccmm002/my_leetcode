// A message containing letters from A-Z is being encoded to numbers using the following mapping way:
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
// Beyond that, now the encoded string can also contain the character '*', which can be treated as one of the numbers from 1 to 9.
//
//
//
//
// Given the encoded message containing digits and the character '*', return the total number of ways to decode it.
//
//
//
// Also, since the answer may be very large, you should return the output mod 109 + 7.
//
//
// Example 1:
//
// Input: "*"
// Output: 9
// Explanation: The encoded message can be decoded to the string: "A", "B", "C", "D", "E", "F", "G", "H", "I".
//
//
//
// Example 2:
//
// Input: "1*"
// Output: 9 + 9 = 18
//
//
//
// Note:
//
// The length of the input string will fit in range [1, 105].
// The input string will only contain the character '*' and digits '0' - '9'.


class Solution {
public:
    int numDecodings(string s) {
        const long long m = 1000000007;
        int n = s.size();
        if (n == 0) return 0;
        vector<long long> v(n + 1, 0);
        v[0] = 1;
        if (s[0] == '0') v[1] = 0;
        else if (s[0] == '*') v[1] = 9;
        else v[1] = 1;
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '*') {
                v[i] += v[i - 1] * 9;
                if (s[i - 2] == '*')
                    v[i] += v[i - 2] * 15;
                if (s[i - 2] == '1')
                    v[i] += v[i - 2] * 9;
                if (s[i - 2] == '2')
                    v[i] += v[i - 2] * 6;
            }
            else {
                if (s[i - 1] != '0') v[i] += v[i - 1];
                if (s[i - 2] == '*') {
                    if (s[i - 1] <= '6') v[i] += v[i - 2] * 2;
                    else v[i] += v[i - 2];
                }
                else {
                    if (s[i - 2] == '0') continue;
                    int two = stoi(s.substr(i - 2, 2));
                    if (two >= 1 && two <= 26) {
                        v[i] += v[i - 2];
                    }
                }
            }
            v[i] = v[i] % m;
        }
        return v[n];
    }
};
