# -*- coding:utf-8 -*-


# Given a string S and a string T, count the number of distinct subsequences of T in S.
#
#
#
# A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ACE" is a subsequence of "ABCDE" while "AEC" is not).
#
#
#
# Here is an example:
# S = "rabbbit", T = "rabbit"
#
#
# Return 3.


class Solution(object):
    def numDistinct(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: int
        """
        ls = len(s)
        lt = len(t)
        if ls == 0 or lt == 0:
            return 0
        f = [[0 for j in range(lt+1)] for i in range(ls+1)]
        for i in range(ls+1):
            f[i][0] = 1
        for i in range(1, ls+1):
            for j in range(1, min(i + 1, lt + 1)):
                f[i][j] = f[i-1][j]
                if s[i-1] == t[j-1]:
                    f[i][j] += f[i-1][j-1]
        return f[ls][lt]
        
