# -*- coding:utf-8 -*-


# Implement regular expression matching with support for '.' and '*'.
#
#
# '.' Matches any single character.
# '*' Matches zero or more of the preceding element.
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
# isMatch("aa", "a*") → true
# isMatch("aa", ".*") → true
# isMatch("ab", ".*") → true
# isMatch("aab", "c*a*b") → true


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
