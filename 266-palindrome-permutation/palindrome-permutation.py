# -*- coding:utf-8 -*-


# Given a string, determine if a permutation of the string could form a palindrome.
#
# Example 1:
#
#
# Input: "code"
# Output: false
#
# Example 2:
#
#
# Input: "aab"
# Output: true
#
# Example 3:
#
#
# Input: "carerac"
# Output: true
#


class Solution(object):
    def canPermutePalindrome(self, s):
        """
        :type s: str
        :rtype: bool
        """
        d = dict()
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        odd = 0
        for k in d:
            if d[k] % 2 == 1:
                odd += 1
        return odd <= 1
    
