# -*- coding:utf-8 -*-


# Given a string, find the length of the longest substring without repeating characters.
#
# Examples:
#
# Given "abcabcbb", the answer is "abc", which the length is 3.
#
# Given "bbbbb", the answer is "b", with the length of 1.
#
# Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        l = len(s)
        if l == 0:
            return 0
        d = dict()
        res = 0
        k = 0
        for i in range(0, l):
            c = s[i]
            if c in d:
                k = max(d[c], k)
            res = max(res, i - k + 1)
            d[c] = i + 1
        return res
        
