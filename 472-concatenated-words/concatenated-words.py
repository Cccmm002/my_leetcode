# -*- coding:utf-8 -*-


# Given a list of words (without duplicates), please write a program that returns all concatenated words in the given list of words.
# A concatenated word is defined as a string that is comprised entirely of at least two shorter words in the given array.
#
# Example:
#
# Input: ["cat","cats","catsdogcats","dog","dogcatsdog","hippopotamuses","rat","ratcatdogcat"]
#
# Output: ["catsdogcats","dogcatsdog","ratcatdogcat"]
#
# Explanation: "catsdogcats" can be concatenated by "cats", "dog" and "cats";  "dogcatsdog" can be concatenated by "dog", "cats" and "dog"; "ratcatdogcat" can be concatenated by "rat", "cat", "dog" and "cat".
#
#
#
# Note:
#
# The number of elements of the given array will not exceed 10,000 
# The length sum of elements in the given array will not exceed 600,000. 
# All the input string will only include lower case letters.
# The returned elements order does not matter.


class Solution(object):
    def findAllConcatenatedWordsInADict(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        dictionary = set(words)
        res = []
        for cur in words:
            dictionary.remove(cur)
            l = len(cur)
            if l == 0:
                continue
            dp = [False] * (l + 1)
            dp[0] = True
            for i in range(1, l + 1):
                for j in range(i - 1, -1, -1):
                    if dp[j]:
                        if cur[j:i] in dictionary:
                            dp[i] = True
                            break
            dictionary.add(cur)
            if dp[l]:
                res.append(cur)
        return res
