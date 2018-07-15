# -*- coding:utf-8 -*-


# Given a set of words (without duplicates), find all word squares you can build from them.
#
# A sequence of words forms a valid word square if the kth row and column read the exact same string, where 0 ≤ k < max(numRows, numColumns).
#
# For example, the word sequence ["ball","area","lead","lady"] forms a word square because each word reads the same both horizontally and vertically.
#
#
# b a l l
# a r e a
# l e a d
# l a d y
#
#
# Note:
#
# There are at least 1 and at most 1000 words.
# All words will have the exact same length.
# Word length is at least 1 and at most 5.
# Each word contains only lowercase English alphabet a-z.
#
#
#
# Example 1:
#
# Input:
# ["area","lead","wall","lady","ball"]
#
# Output:
# [
#   [ "wall",
#     "area",
#     "lead",
#     "lady"
#   ],
#   [ "ball",
#     "area",
#     "lead",
#     "lady"
#   ]
# ]
#
# Explanation:
# The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
#
#
#
# Example 2:
#
# Input:
# ["abat","baba","atan","atal"]
#
# Output:
# [
#   [ "baba",
#     "abat",
#     "baba",
#     "atan"
#   ],
#   [ "baba",
#     "abat",
#     "baba",
#     "atal"
#   ]
# ]
#
# Explanation:
# The output consists of two word squares. The order of output does not matter (just the order of words in each word square matters).
#
#


class Solution(object):
    def __init__(self):
        self.words = None
        self.result = []
        
    def calc(self, order):
        cur_len = len(order)
        if cur_len == 0:
            for w in self.words['']:
                self.calc([w])
            return
        n = len(order[0])
        if cur_len == n:
            self.result.append(order)
            return
        prefix = ''
        for i in range(cur_len):
            prefix += order[i][cur_len]
        if prefix not in self.words:
            return
        for w in self.words[prefix]:
            no = order[:] + [w]
            self.calc(no)
        
    def wordSquares(self, words):
        """
        :type words: List[str]
        :rtype: List[List[str]]
        """
        self.words = dict()
        self.words[''] = words[:]
        for w in words:
            for i in range(len(w)):
                cur = w[:i + 1]
                if cur in self.words:
                    self.words[cur].append(w)
                else:
                    self.words[cur] = [w]
        self.calc([])
        return self.result
    
