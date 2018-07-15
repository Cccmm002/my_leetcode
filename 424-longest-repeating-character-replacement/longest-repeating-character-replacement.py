# -*- coding:utf-8 -*-


# Given a string that consists of only uppercase English letters, you can replace any letter in the string with another letter at most k times. Find the length of a longest substring containing all repeating letters you can get after performing the above operations.
#
# Note:
# Both the string's length and k will not exceed 104.
#
#
#
# Example 1:
#
# Input:
# s = "ABAB", k = 2
#
# Output:
# 4
#
# Explanation:
# Replace the two 'A's with two 'B's or vice versa.
#
#
#
#
# Example 2:
#
# Input:
# s = "AABABBA", k = 1
#
# Output:
# 4
#
# Explanation:
# Replace the one 'A' in the middle with 'B' and form "AABBBBA".
# The substring "BBBB" has the longest repeating letters, which is 4.
#
#


class Solution(object):
    def maxOccur(self, d):
        total = 0
        curMax = 0
        for k in d:
            total += d[k]
            curMax = max(curMax, d[k])
        return total - curMax
    
    def characterReplacement(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: int
        """
        n = len(s)
        if n == 0: return 0
        beg, end = 0, 0
        d = dict()
        res = 0
        while beg < n:
            while end <= n:
                if self.maxOccur(d) > k:
                    break
                res = max(res, end - beg)
                if end < n:
                    if s[end] in d:
                        d[s[end]] += 1
                    else:
                        d[s[end]] = 1
                end += 1
            d[s[beg]] -= 1
            beg += 1
        return res
    
