# -*- coding:utf-8 -*-


#
# Given a set of keywords words and a string S, make all appearances of all keywords in S bold.  Any letters between <b> and </b> tags become bold.
#
# The returned string should use the least number of tags possible, and of course the tags should form a valid combination.
#
#
# For example, given that words = ["ab", "bc"] and  S = "aabcd", we should return "a<b>abc</b>d".  Note that returning "a<b>a<b>b</b>c</b>d" would use more tags, so it is incorrect.
#
#
# Note:
# words has length in range [0, 50].
# words[i] has length in range [1, 10].
# S has length in range [0, 500].
# All characters in words[i] and S are lowercase letters.
#


import re

class Solution(object):
    def boldWords(self, dict, s):
        """
        :type words: List[str]
        :type S: str
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
    
