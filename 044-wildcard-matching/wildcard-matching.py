# -*- coding:utf-8 -*-


# Given an input string (s) and a pattern (p), implement wildcard pattern matching with support for '?' and '*'.
#
#
# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# 	s could be empty and contains only lowercase letters a-z.
# 	p could be empty and contains only lowercase letters a-z, and characters like ? or *.
#
#
# Example 1:
#
#
# Input:
# s = "aa"
# p = "a"
# Output: false
# Explanation: "a" does not match the entire string "aa".
#
#
# Example 2:
#
#
# Input:
# s = "aa"
# p = "*"
# Output: true
# Explanation: '*' matches any sequence.
#
#
# Example 3:
#
#
# Input:
# s = "cb"
# p = "?a"
# Output: false
# Explanation: '?' matches 'c', but the second letter is 'a', which does not match 'b'.
#
#
# Example 4:
#
#
# Input:
# s = "adceb"
# p = "*a*b"
# Output: true
# Explanation: The first '*' matches the empty sequence, while the second '*' matches the substring "dce".
#
#
# Example 5:
#
#
# Input:
# s = "acdcb"
# p = "a*c?b"
# Output: false
#
#


class Solution(object):
    def isMatch(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: bool
        """
        len_s = len(s)
        len_p = len(p)
        arr = [[False for i in range(len_p + 1)] for j in range(len_s + 1)]
        arr[0][0] = True
        for i in range(0, len_s + 1):
            for r in range(1, len_p + 1):
                if i == 0:
                    if p[r-1] == '*':
                        arr[i][r] = arr[i][r-1]
                    else:
                        arr[i][r] = False
                    continue
                if s[i-1] == p[r-1] or p[r-1] == '?':
                    arr[i][r] = arr[i-1][r-1]
                elif p[r-1] == '*':
                    arr[i][r] = arr[i][r-1] or arr[i-1][r]
                else:
                    arr[i][r] = False
        return arr[len_s][len_p]
