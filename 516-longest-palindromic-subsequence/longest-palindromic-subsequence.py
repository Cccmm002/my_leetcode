# -*- coding:utf-8 -*-


#
# Given a string s, find the longest palindromic subsequence's length in s. You may assume that the maximum length of s is 1000.
#
#
# Example 1:
# Input: 
#
# "bbbab"
#
# Output: 
#
# 4
#
# One possible longest palindromic subsequence is "bbbb".
#
#
# Example 2:
# Input:
#
# "cbbd"
#
# Output:
#
# 2
#
# One possible longest palindromic subsequence is "bb".
#


class Solution(object):
    def longestPalindromeSubseq(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        dp = [[1 for _ in range(n)] for _ in range(n)]
        for i in range(n - 1):
            if s[i] == s[i + 1]:
                dp[i][i + 1] = 2
        for dis in range(2, n):
            for i in range(n - dis):
                j = i + dis
                if s[i] == s[j]:
                    dp[i][j] = 2 + dp[i + 1][j - 1]
                else:
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1])
        return dp[0][n - 1]
    
