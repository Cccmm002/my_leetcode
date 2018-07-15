# -*- coding:utf-8 -*-


# Given a string s , find the length of the longest substring t  that contains at most 2 distinct characters.
#
# Example 1:
#
#
# Input: "eceba"
# Output: 3
# Explanation: t is "ece" which its length is 3.
#
#
# Example 2:
#
#
# Input: "ccaabbb"
# Output: 5
# Explanation: t is "aabbb" which its length is 5.
#
#


class Solution(object):
    def lengthOfLongestSubstringTwoDistinct(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        d = dict()
        l = 0
        res = 0
        for r in range(n):
            if s[r] in d:
                d[s[r]] += 1
            else:
                d[s[r]] = 1
            while len(d) > 2:
                d[s[l]] -= 1
                if d[s[l]] == 0:
                    del d[s[l]]
                l += 1
            res = max(res, r - l + 1)
        return res
    
