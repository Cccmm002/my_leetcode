# -*- coding:utf-8 -*-


# Given a string s and a non-empty string p, find all the start indices of p's anagrams in s.
#
# Strings consists of lowercase English letters only and the length of both strings s and p will not be larger than 20,100.
#
# The order of output does not matter.
#
# Example 1:
#
# Input:
# s: "cbaebabacd" p: "abc"
#
# Output:
# [0, 6]
#
# Explanation:
# The substring with start index = 0 is "cba", which is an anagram of "abc".
# The substring with start index = 6 is "bac", which is an anagram of "abc".
#
#
#
# Example 2:
#
# Input:
# s: "abab" p: "ab"
#
# Output:
# [0, 1, 2]
#
# Explanation:
# The substring with start index = 0 is "ab", which is an anagram of "ab".
# The substring with start index = 1 is "ba", which is an anagram of "ab".
# The substring with start index = 2 is "ab", which is an anagram of "ab".


class Solution(object):
    def findAnagrams(self, s, p):
        """
        :type s: str
        :type p: str
        :rtype: List[int]
        """
        res = []
        lp = len(p)
        if lp > len(s):
            return res
        dp = dict()
        for i in range(lp):
            c = p[i]
            if c in dp:
                dp[c] += 1
            else:
                dp[c] = 1
        d = dict()
        for i in range(lp):
            c = s[i]
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        if d == dp:
            res.append(0)
        for i in range(1, len(s) - lp + 1):
            pc = s[i-1]
            if d[pc] == 1:
                del d[pc]
            else:
                d[pc] -= 1
            c = s[i+lp-1]
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
            if d == dp:
                res.append(i)
        return res
