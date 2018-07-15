// Given strings S and T, find the minimum (contiguous) substring W of S, so that T is a subsequence of W.
//
// If there is no such window in S that covers all characters in T, return the empty string "".  If there are multiple such minimum-length windows, return the one with the left-most starting index.
//
//
// Example 1:
//
// Input: 
// S = "abcdebdde", T = "bde"
// Output: "bcde"
// Explanation: 
// "bcde" is the answer because it occurs before "bdde" which has the same length.
// "deb" is not a smaller window because the elements of T in the window must occur in order.
//
//
//
// Note:
// All the strings in the input will only contain lowercase letters.
// The length of S will be in the range [1, 20000].
// The length of T will be in the range [1, 100].
//


class Solution {
public:
    string minWindow(string S, string T) {
        int m = S.size();
        int n = T.size();
        vector<vector<int>> dp (n + 1, vector<int>(m + 1, INT_MAX/2)); 
        dp[n] = vector<int>(m + 1, 0);

        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if(T[i] == S[j])
                    dp[i][j] = 1 + dp[i+1][j+1];
                else
                    dp[i][j] = 1 + dp[i][j+1];
            }
        }

        int l, r, min_len = INT_MAX/2;

        for (int i = 0; i < m; ++i) {
            if(dp[0][i] < min_len) {
                min_len = dp[0][i];
                l = i, r = i + min_len;
            }
        }

        if(min_len == INT_MAX/2) 
            return "";
        else
            return S.substr(l, r - l);
    }
};
