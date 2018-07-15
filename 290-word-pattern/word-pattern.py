# -*- coding:utf-8 -*-


# Given a pattern and a string str, find if str follows the same pattern.
#
# Here follow means a full match, such that there is a bijection between a letter in pattern and a non-empty word in str.
#
# Example 1:
#
#
# Input: pattern = "abba", str = "dog cat cat dog"
# Output: true
#
# Example 2:
#
#
# Input:pattern = "abba", str = "dog cat cat fish"
# Output: false
#
# Example 3:
#
#
# Input: pattern = "aaaa", str = "dog cat cat dog"
# Output: false
#
# Example 4:
#
#
# Input: pattern = "abba", str = "dog dog dog dog"
# Output: false
#
# Notes:
# You may assume pattern contains only lowercase letters, and str contains lowercase letters separated by a single space.
#


class Solution(object):
    def wordPattern(self, pattern, str):
        """
        :type pattern: str
        :type str: str
        :rtype: bool
        """
        right = str.split(' ')
        d1 = dict()
        d2 = dict()
        lp = len(pattern)
        ls = len(right)
        if not lp == ls:
            return False
        for i in range(lp):
            if pattern[i] in d1:
                if d1[pattern[i]] != right[i]:
                    return False
            else:
                d1[pattern[i]] = right[i]
            if right[i] in d2:
                if d2[right[i]] != pattern[i]:
                    return False
            else:
                d2[right[i]] = pattern[i]
        return True
        
