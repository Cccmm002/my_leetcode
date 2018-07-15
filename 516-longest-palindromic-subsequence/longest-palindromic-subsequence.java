//
// Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
//
//
// Example 1:
// Input: 
//
// "bbbab"
//
// Output: 
//
// 4
//
// One possible longest palindromic subsequence is "bbbb".
//
//
// Example 2:
// Input:
//
// "cbbd"
//
// Output:
//
// 2
//
// One possible longest palindromic subsequence is "bb".
//


class Solution {
    public int longestPalindromeSubseq(String s) {
        int n = s.length();
        int[][] state = new int[n][n];
        for (int i = 0; i < n; i++) state[i][i] = 1;
        for (int i = 0; i < n-1; i++) {
            if (s.charAt(i) == s.charAt(i+1)) state[i][i+1] = 2;
            else state[i][i+1] = 1;
        }
        for (int dis = 2; dis < n; dis++) {
            for (int i = 0; i < n; i++) {
                if ((i+dis) >= n) continue;
                if (s.charAt(i) == s.charAt(i+dis)) state[i][i+dis] = state[i+1][i+dis-1] + 2;
                else state[i][i+dis] = Math.max(state[i+1][i+dis], state[i][i+dis-1]);
            }
        }
        return state[0][n-1];
    }
}
