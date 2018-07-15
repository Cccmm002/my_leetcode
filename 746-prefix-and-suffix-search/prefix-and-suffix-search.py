# -*- coding:utf-8 -*-


#
# Given many words, words[i] has weight i.
#
# Design a class WordFilter that supports one function, WordFilter.f(String prefix, String suffix).
# It will return the word with given prefix and suffix with maximum weight.  If no word exists, return -1.
#
#
# Examples:
#
# Input:
# WordFilter(["apple"])
# WordFilter.f("a", "e") // returns 0
# WordFilter.f("b", "") // returns -1
#
#
# Note:
#
# words has length in range [1, 15000].
# For each test case, up to words.length queries WordFilter.f may be made.
# words[i] has length in range [1, 10].
# prefix, suffix have lengths in range [0, 10].
# words[i] and prefix, suffix queries consist of lowercase letters only.
#
#


class WordFilter(object):

    def __init__(self, words):
        """
        :type words: List[str]
        """
        self.d = dict()
        length = len(words)
        for i in range(length):
            n = len(words[i])
            for p in range(n + 1):
                prefix = words[i][:p]
                if prefix not in self.d:
                    self.d[prefix] = dict()
                for s in range(n + 1):
                    suffix = words[i][s:]
                    if suffix not in self.d[prefix]:
                        self.d[prefix][suffix] = i
                    else:
                        self.d[prefix][suffix] = max(self.d[prefix][suffix], i)

    def f(self, prefix, suffix):
        """
        :type prefix: str
        :type suffix: str
        :rtype: int
        """
        if prefix not in self.d:
            return -1
        if suffix not in self.d[prefix]:
            return -1
        else:
            return self.d[prefix][suffix]


# Your WordFilter object will be instantiated and called as such:
# obj = WordFilter(words)
# param_1 = obj.f(prefix,suffix)
