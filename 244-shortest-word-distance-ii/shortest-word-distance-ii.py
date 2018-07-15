# -*- coding:utf-8 -*-


# Design a class which receives a list of words in the constructor, and implements a method that takes two words word1 and word2 and return the shortest distance between these two words in the list. Your method will be called repeatedly many times with different parameters. 
#
# Example:
# Assume that words = ["practice", "makes", "perfect", "coding", "makes"].
#
#
# Input: word1 = “coding”, word2 = “practice”
# Output: 3
#
#
#
# Input: word1 = "makes", word2 = "coding"
# Output: 1
#
# Note:
# You may assume that word1 does not equal to word2, and word1 and word2 are both in the list.
#


class WordDistance(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.d = dict()
        for i in range(len(words)):
            w = words[i]
            if w in self.d:
                self.d[w].append(i)
            else:
                self.d[w] = [i]

    def shortest(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        l1 = self.d[word1]
        l2 = self.d[word2]
        res = float('inf')
        for i in range(len(l1)):
            nl = list(map(lambda x: abs(x - l1[i]), l2))
            res = min(res, min(nl))
        return res


# Your WordDistance object will be instantiated and called as such:
# obj = WordDistance(words)
# param_1 = obj.shortest(word1,word2)
