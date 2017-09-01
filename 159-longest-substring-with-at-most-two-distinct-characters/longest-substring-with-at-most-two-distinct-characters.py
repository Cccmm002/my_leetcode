# -*- coding:utf-8 -*-


# Given a string, find the length of the longest substring T that contains at most 2 distinct characters.
#
#
#
# For example,
#
# Given s = “eceba”,
#
#
#
# T is "ece" which its length is 3.


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
    
