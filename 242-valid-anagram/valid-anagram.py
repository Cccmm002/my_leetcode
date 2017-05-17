# -*- coding:utf-8 -*-


# Given two strings s and t, write a function to determine if t is an anagram of s. 
#
# For example,
# s = "anagram", t = "nagaram", return true.
# s = "rat", t = "car", return false.
#
#
# Note:
# You may assume the string contains only lowercase alphabets.
#
# Follow up:
# What if the inputs contain unicode characters? How would you adapt your solution to such case?


class Solution(object):
    def isAnagram(self, s, t):
        """
        :type s: str
        :type t: str
        :rtype: bool
        """
        d1 = dict()
        d2 = dict()
        for c in s:
            if c in d1:
                d1[c] += 1
            else:
                d1[c] = 1
        for c in t:
            if c in d2:
                d2[c] += 1
            else:
                d2[c] = 1
        return d1 == d2
        
