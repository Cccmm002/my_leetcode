# -*- coding:utf-8 -*-


# Given a string s and a list of strings dict, you need to add a closed pair of bold tag <b> and </b> to wrap the substrings in s that exist in dict. If two such substrings overlap, you need to wrap them together by only one pair of closed bold tag. Also, if two substrings wrapped by bold tags are consecutive, you need to combine them. 
#
# Example 1:
#
# Input: 
# s = "abcxyz123"
# dict = ["abc","123"]
# Output:
# "<b>abc</b>xyz<b>123</b>"
#
#
#
# Example 2:
#
# Input: 
# s = "aaabbcc"
# dict = ["aaa","aab","bc"]
# Output:
# "<b>aaabbc</b>c"
#
#
#
# Note:
#
# The given dict won't contain duplicates, and its length won't exceed 100.
# All the strings in input have length in range [1, 1000]. 
#
#


import re

class Solution(object):
    def addBoldTag(self, s, dict):
        """
        :type s: str
        :type dict: List[str]
        :rtype: str
        """
        intervals = []
        for w in dict:
            r = '(?=' + w + ')'
            l = [m.start() for m in re.finditer(r, s)]
            for i in l:
                intervals.append((i, i + len(w) - 1))
        if len(intervals) == 0:
            return s
        intervals.sort()
        print(intervals)
        merged = []
        left = intervals[0][0]
        right = intervals[0][1]
        for i in range(1, len(intervals)):
            if intervals[i][0] <= right + 1:
                right = max(right, intervals[i][1])
            else:
                merged.append((left, right))
                left = intervals[i][0]
                right = intervals[i][1]
        merged.append((left, right))
        res = s[:merged[0][0]]
        for i in range(len(merged)):
            res += '<b>' + s[merged[i][0]:merged[i][1] + 1] + '</b>'
            if i < len(merged) - 1:
                res += s[merged[i][1] + 1:merged[i + 1][0]]
            else:
                res += s[merged[i][1] + 1:]
        return res
    
