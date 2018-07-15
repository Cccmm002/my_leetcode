# -*- coding:utf-8 -*-


#
# Given two words word1 and word2, find the minimum number of steps required to make word1 and word2 the same, where in each step you can delete one character in either string.
#
#
# Example 1:
#
# Input: "sea", "eat"
# Output: 2
# Explanation: You need one step to make "sea" to "ea" and another step to make "eat" to "ea".
#
#
#
# Note:
#
# The length of given words won't exceed 500.
# Characters in given words can only be lower-case letters.
#
#


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        len1 = len(word1)
        len2 = len(word2)
        arr = [[0 for i in range(len2 + 1)] for j in range(len1 + 1)]
        for i in range(1, len2 + 1):
            arr[0][i] = i
        for i in range(1, len1 + 1):
            arr[i][0] = i
        for i in range(1, len1 + 1):
            for j in range(1, len2 + 1):
                if word1[i - 1] == word2[j - 1]:
                    arr[i][j] = arr[i-1][j-1]
                else:
                    arr[i][j] = min(arr[i][j-1], arr[i-1][j]) + 1
        return arr[len1][len2]
