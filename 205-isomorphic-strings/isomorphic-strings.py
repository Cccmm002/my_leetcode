# -*- coding:utf-8 -*-


# Given two strings s and t, determine if they are isomorphic.
#
# Two strings are isomorphic if the characters in s can be replaced to get t.
#
# All occurrences of a character must be replaced with another character while preserving the order of characters. No two characters may map to the same character but a character may map to itself.
#
# For example,
# Given "egg", "add", return true.
#
# Given "foo", "bar", return false.
#
# Given "paper", "title", return true.
#
# Note:
# You may assume both s and t have the same length.


class Solution(object):
    def isIsomorphic(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        d1 = dict()
        d2 = dict()
        s1 = set()
        s2 = set()
        for i in range(len(s)):
            if s[i] in d1:
                d1[s[i]].append(i)
            else:
                d1[s[i]] = [i]
        for k in d1:
            s1.add(tuple(d1[k]))
        for i in range(len(t)):
            if t[i] in d2:
                d2[t[i]].append(i)
            else:
                d2[t[i]] = [i]
        for k in d2:
            s2.add(tuple(d2[k]))
        return s1 == s2
        
