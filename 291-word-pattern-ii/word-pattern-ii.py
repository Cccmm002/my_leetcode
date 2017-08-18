# -*- coding:utf-8 -*-


# Given a pattern and a string str, find if str follows the same pattern.
#  Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty substring in str.
#
# Examples:
#
# pattern = "abab", str = "redblueredblue" should return true.
# pattern = "aaaa", str = "asdasdasdasd" should return true.
# pattern = "aabb", str = "xyzabcxzyabc" should return false.
#
#
#
#
# Notes:
# You may assume both pattern and str contains only lowercase letters.


class Solution(object):
    def match(self, pattern, s, d, revd):
        if len(pattern) == 0:
            return len(s) == 0
        if len(pattern) > len(s):
            return False
        cur = pattern[0]
        if cur in d:
            n = len(d[cur])
            if d[cur] != s[:n]:
                return False
            else:
                return self.match(pattern[1:], s[n:], d, revd)
        for l in range(1, len(s) + 1):
            if s[:l] in revd: continue
            d[pattern[0]] = s[:l]
            revd[s[:l]] = pattern[0]
            nxt = self.match(pattern[1:], s[l:], d, revd)
            if nxt:
                return True
            else:
                del revd[s[:l]]
                del d[pattern[0]]
        return False
        
    def wordPatternMatch(self, pattern, s):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        d = dict()
        revd = dict()
        return self.match(pattern, s, d, revd)
    
