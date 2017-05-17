# -*- coding:utf-8 -*-


# Implement wildcard pattern matching with support for '?' and '*'.
#
#
# '?' Matches any single character.
# '*' Matches any sequence of characters (including the empty sequence).
#
# The matching should cover the entire input string (not partial).
#
# The function prototype should be:
# bool isMatch(const char *s, const char *p)
#
# Some examples:
# isMatch("aa","a") → false
# isMatch("aa","aa") → true
# isMatch("aaa","aa") → false
# isMatch("aa", "*") → true
# isMatch("aa", "a*") → true
# isMatch("ab", "?*") → true
# isMatch("aab", "c*a*b") → false


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
