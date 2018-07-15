# -*- coding:utf-8 -*-


#
# Given a string, find the length of the longest substring T that contains at most k distinct characters.
#
#
#
# For example,
#
# Given s = “eceba” and k = 2,
#
#
#
# T is "ece" which its length is 3.
#


class Solution(object):
    def lengthOfLongestSubstringKDistinct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        beg, end = 0, 0
        d = dict()
        res = 0
        while beg < n:
            while end <= n:
                if len(d) > k:
                    break
                res = max(res, end - beg)
                if end < n:
                    if s[end] in d:
                        d[s[end]] += 1
                    else:
                        d[s[end]] = 1
                end += 1
            d[s[beg]] -= 1
            if d[s[beg]] == 0:
                del d[s[beg]]
            beg += 1
        return res
                
