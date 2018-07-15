# -*- coding:utf-8 -*-


# There is a new alien language which uses the latin alphabet. However, the order among letters are unknown to you. You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language. Derive the order of letters in this language.
#
# Example 1:
#
#
# Input:
# [
#   "wrt",
#   "wrf",
#   "er",
#   "ett",
#   "rftt"
# ]
#
# Output: "wertf"
#
#
# Example 2:
#
#
# Input:
# [
#   "z",
#   "x"
# ]
#
# Output: "zx"
#
#
# Example 3:
#
#
# Input:
# [
#   "z",
#   "x",
#   "z"
# ] 
#
# Output: "" 
#
# Explanation: The order is invalid, so return "".
#
#
# Note:
#
#
# 	You may assume all letters are in lowercase.
# 	You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
# 	If the order is invalid, return an empty string.
# 	There may be multiple valid order of letters, return any one of them is fine.
#
#


from collections import deque

class Solution(object):
    def __init__(self):
        self.graph = dict()
        self.in_count = dict()
    
    def initDict(self, w):
        for c in w:
            if c not in self.in_count:
                self.in_count[c] = 0
            if c not in self.graph:
                self.graph[c] = set()
    
    def wordsCompare(self, w1, w2):
        len1, len2 = len(w1), len(w2)
        for i in range(min(len1, len2)):
            if w1[i] == w2[i]: continue
            if w2[i] not in self.graph[w1[i]]:
                self.graph[w1[i]].add(w2[i])
                self.in_count[w2[i]] += 1
            break
        
    def alienOrder(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        words_count = len(words)
        for i in range(words_count):
            self.initDict(words[i])
            if i > 0:
                self.wordsCompare(words[i - 1], words[i])
        
        result = []
        zero_set = deque()
        all_nodes = set(self.in_count.keys())
        for k in self.in_count:
            if self.in_count[k] == 0:
                zero_set.append(k)
        while len(zero_set) > 0:
            current = zero_set.popleft()
            all_nodes.remove(current)
            result.append(current)
            for node in self.graph[current]:
                self.in_count[node] -= 1
                if self.in_count[node] == 0:
                    zero_set.append(node)
        if len(all_nodes) > 0:
            return ""
        else:
            return "".join(result)
        
