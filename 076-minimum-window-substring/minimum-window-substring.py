# -*- coding:utf-8 -*-


# Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
#
#
#
# For example,
# S = "ADOBECODEBANC"
# T = "ABC"
#
#
# Minimum window is "BANC".
#
#
#
# Note:
# If there is no such window in S that covers all characters in T, return the empty string "".
#
#
# If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


class Solution(object):
    def minWindow(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: str
        """
        d = dict()
        for c in t:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        counter = len(t)
        begin = 0
        end = 1
        res = float('inf')
        res_str = ""
        while end <= len(s):
            c = s[end - 1]
            if c in d:
                d[c] -= 1
                if d[c] >= 0:
                    counter -= 1
            while counter == 0 and begin < end:
                if (end - begin) < res:
                    res = end - begin
                    res_str = s[begin:end]
                dc = s[begin]
                if dc in d:
                    d[dc] += 1
                    if d[dc] > 0:
                        counter += 1
                begin += 1
            end += 1
        return res_str
        
