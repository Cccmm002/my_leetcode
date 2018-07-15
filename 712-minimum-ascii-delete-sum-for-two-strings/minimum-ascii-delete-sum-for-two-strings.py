# -*- coding:utf-8 -*-


# Given two strings s1, s2, find the lowest ASCII sum of deleted characters to make two strings equal.
#
# Example 1:
#
# Input: s1 = "sea", s2 = "eat"
# Output: 231
# Explanation: Deleting "s" from "sea" adds the ASCII value of "s" (115) to the sum.
# Deleting "t" from "eat" adds 116 to the sum.
# At the end, both strings are equal, and 115 + 116 = 231 is the minimum sum possible to achieve this.
#
#
#
# Example 2:
#
# Input: s1 = "delete", s2 = "leet"
# Output: 403
# Explanation: Deleting "dee" from "delete" to turn the string into "let",
# adds 100[d]+101[e]+101[e] to the sum.  Deleting "e" from "leet" adds 101[e] to the sum.
# At the end, both strings are equal to "let", and the answer is 100+101+101+101 = 403.
# If instead we turned both strings into "lee" or "eet", we would get answers of 433 or 417, which are higher.
#
#
#
# Note:
# 0 < s1.length, s2.length <= 1000.
# All elements of each string will have an ASCII value in [97, 122]. 
#


class Solution(object):
    def minimumDeleteSum(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: int
        """
        n1 = len(s1)
        n2 = len(s2)
        arr = [[float('inf') for _ in range(n2 + 1)] for _ in range(n1 + 1)]
        arr[0][0] = 0
        for i in range(1, n1 + 1):
            arr[i][0] = arr[i - 1][0] + ord(s1[i - 1])
        for i in range(1, n2 + 1):
            arr[0][i] = arr[0][i - 1] + ord(s2[i - 1])
        for i in range(1, n1 + 1):
            for j in range(1, n2 + 1):
                if s1[i - 1] == s2[j - 1]:
                    arr[i][j] = arr[i - 1][j - 1]
                else:
                    a = arr[i - 1][j] + ord(s1[i - 1])
                    b = arr[i][j - 1] + ord(s2[j - 1])
                    c = arr[i - 1][j - 1] + ord(s1[i - 1]) + ord(s2[j - 1])
                    arr[i][j] = min((a, b, c))
        return arr[n1][n2]
    
