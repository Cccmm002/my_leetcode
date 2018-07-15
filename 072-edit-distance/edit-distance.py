# -*- coding:utf-8 -*-


# Given two words word1 and word2, find the minimum number of operations required to convert word1 to word2.
#
# You have the following 3 operations permitted on a word:
#
#
# 	Insert a character
# 	Delete a character
# 	Replace a character
#
#
# Example 1:
#
#
# Input: word1 = "horse", word2 = "ros"
# Output: 3
# Explanation: 
# horse -> rorse (replace 'h' with 'r')
# rorse -> rose (remove 'r')
# rose -> ros (remove 'e')
#
#
# Example 2:
#
#
# Input: word1 = "intention", word2 = "execution"
# Output: 5
# Explanation: 
# intention -> inention (remove 't')
# inention -> enention (replace 'i' with 'e')
# enention -> exention (replace 'n' with 'x')
# exention -> exection (replace 'n' with 'c')
# exection -> execution (insert 'u')
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
                delete = arr[i-1][j] + 1
                insert = arr[i][j-1] + 1
                mod = arr[i-1][j-1]
                if not word1[i-1] == word2[j-1]:
                    mod += 1
                arr[i][j] = min(delete, insert, mod)
        return arr[len1][len2]
        
