# -*- coding:utf-8 -*-


# Given an input string (s) and a pattern (p), implement regular expression matching with support for '.' and '*'.
#
#
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
#
#
# The matching should cover the entire input string (not partial).
#
# Note:
#
#
# 	s could be empty and contains only lowercase letters a-z.
# 	p could be empty and contains only lowercase letters a-z, and characters like . or *.
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
# p = "a*"
# Output: true
# Explanation: '*' means zero or more of the precedeng element, 'a'. Therefore, by repeating 'a' once, it becomes "aa".
#
#
# Example 3:
#
#
# Input:
# s = "ab"
# p = ".*"
# Output: true
# Explanation: ".*" means "zero or more (*) of any character (.)".
#
#
# Example 4:
#
#
# Input:
# s = "aab"
# p = "c*a*b"
# Output: true
# Explanation: c can be repeated 0 times, a can be repeated 1 time. Therefore it matches "aab".
#
#
# Example 5:
#
#
# Input:
# s = "mississippi"
# p = "mis*is*p*."
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
                    if r == 1:
                        arr[i][r] = False
                    elif p[r-1] == '*':
                        arr[i][r] = arr[i][r-2]
                    else:
                        arr[i][r] = False
                    continue
                if s[i-1] == p[r-1] or p[r-1] == '.':
                    arr[i][r] = arr[i-1][r-1]
                elif p[r-1] == '*' and (p[r-2] == s[i-1] or p[r-2] == '.'):
                    arr[i][r] = arr[i-1][r] or arr[i][r-2]
                elif p[r-1] == '*':
                    arr[i][r] = arr[i][r-2]
                else:
                    arr[i][r] = False
        print(arr)
        return arr[len_s][len_p]
