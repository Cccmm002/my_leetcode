# -*- coding:utf-8 -*-


# Given two strings s1 and s2, write a function to return true if s2 contains the permutation of s1. In other words, one of the first string's permutations is the substring of the second string.
#
# Example 1:
#
# Input:s1 = "ab" s2 = "eidbaooo"
# Output:True
# Explanation: s2 contains one permutation of s1 ("ba").
#
#
#
# Example 2:
#
# Input:s1= "ab" s2 = "eidboaoo"
# Output: False
#
#
#
# Note:
#
# The input strings only contain lower case letters.
# The length of both given strings is in range [1, 10,000].
#
#


class Solution(object):
    def checkInclusion(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        pd = dict()
        for c in s1:
            if c in pd:
                pd[c] += 1
            else:
                pd[c] = 1
        l1 = len(s1)
        l2 = len(s2)
        if l1 > l2:
            return False
        cd = dict()
        for i in range(0, l1):
            c = s2[i]
            if c in cd:
                cd[c] += 1
            else:
                cd[c] = 1
        if cd == pd:
            return True
        for i in range(1, l2 - l1 + 1):
            pc = s2[i - 1]
            cd[pc] -= 1
            if cd[pc] == 0:
                del cd[pc]
            nc = s2[i + l1 - 1]
            if nc in cd:
                cd[nc] += 1
            else:
                cd[nc] = 1
            if cd == pd:
                return True
        return False
        
