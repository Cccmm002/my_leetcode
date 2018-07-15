# -*- coding:utf-8 -*-


# Given a string s, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
#
# Example 1:
#
#
# Input: "aacecaaa"
# Output: "aaacecaaa"
#
#
# Example 2:
#
#
# Input: "abcd"
# Output: "dcbabcd"
#


class Solution(object):
    def shortestPalindrome(self, s):
        """
        :type s: str
        :rtype: str
        """
        rev = s[::-1]
        ns = s + '#' + rev
        n = len(ns)
        p = [0 for _ in range(n)]
        for i in range(1, n):
            t = p[i - 1]
            while t > 0 and ns[i] != ns[t]:
                t = p[t - 1]
            if ns[i] == ns[t]:
                t += 1
            p[i] = t
        cm = p[n - 1]
        return rev[:len(s) - cm] + s
    
