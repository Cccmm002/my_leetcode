# -*- coding:utf-8 -*-


# This is a follow up of Shortest Word Distance. The only difference is now word1 could be the same as word2.
#
# Given a list of words and two words word1 and word2, return the shortest distance between these two words in the list.
#
# word1 and word2 may be the same and they represent two individual words in the list.
# For example,
# Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
#
#
# Given word1 = “makes”, word2 = “coding”, return 1.
# Given word1 = "makes", word2 = "makes", return 3.
#
#
#
# Note:
# You may assume word1 and word2 are both in the list.


class Solution(object):
    def shortestWordDistance(self, words, word1, word2):
        """
        :type words: List[str]
        :type word1: str
        :type word2: str
        :rtype: int
        """
        if word1 != word2:
            d = dict()
            res = float('inf')
            for i in range(len(words)):
                if words[i] == word1:
                    if word2 in d:
                        res = min(res, i - d[word2])
                elif words[i] == word2:
                    if word1 in d:
                        res = min(res, i - d[word1])
                d[words[i]] = i
            return res
        else:
            prev = None
            res = float('inf')
            for i in range(len(words)):
                cur = words[i]
                if cur == word1:
                    if prev is not None:
                        res = min(res, i - prev)
                    prev = i
            return res
    
