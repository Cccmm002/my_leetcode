# -*- coding:utf-8 -*-


# Given a string S, you are allowed to convert it to a palindrome by adding characters in front of it. Find and return the shortest palindrome you can find by performing this transformation.
#
#
# For example: 
# Given "aacecaaa", return "aaacecaaa".
# Given "abcd", return "dcbabcd".
#
# Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Thanks to @Freezen for additional test cases.


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
    
