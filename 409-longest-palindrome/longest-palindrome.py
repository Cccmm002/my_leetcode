# -*- coding:utf-8 -*-


# Given a string which consists of lowercase or uppercase letters, find the length of the longest palindromes that can be built with those letters.
#
# This is case sensitive, for example "Aa" is not considered a palindrome here.
#
# Note:
# Assume the length of given string will not exceed 1,010.
#
#
# Example: 
#
# Input:
# "abccccdd"
#
# Output:
# 7
#
# Explanation:
# One longest palindrome that can be built is "dccaccd", whose length is 7.


class Solution(object):
    def longestPalindrome(self, s):
        """
        :type s: str
        :rtype: int
        """
        n = len(s)
        if n == 0: return 0;
        d = dict()
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        odds = 0
        sum = 0
        for k in d:
            sum += d[k]
            if d[k]%2 != 0:
                odds += 1
        if odds >= 2:
            sum -= odds - 1
        return sum
        
