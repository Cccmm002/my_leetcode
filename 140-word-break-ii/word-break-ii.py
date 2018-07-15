# -*- coding:utf-8 -*-


# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
#
# Note:
#
#
# 	The same word in the dictionary may be reused multiple times in the segmentation.
# 	You may assume the dictionary does not contain duplicate words.
#
#
# Example 1:
#
#
# Input:
# s = "catsanddog"
# wordDict = ["cat", "cats", "and", "sand", "dog"]
# Output:
# [
#   "cats and dog",
#   "cat sand dog"
# ]
#
#
# Example 2:
#
#
# Input:
# s = "pineapplepenapple"
# wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
# Output:
# [
#   "pine apple pen apple",
#   "pineapple pen apple",
#   "pine applepen apple"
# ]
# Explanation: Note that you are allowed to reuse a dictionary word.
#
#
# Example 3:
#
#
# Input:
# s = "catsandog"
# wordDict = ["cats", "dog", "sand", "and", "cat"]
# Output:
# []
#


class Solution(object):
    def __init__(self):
        self.d = dict()
        self.words = set()
    
    def find(self, s):
        n = len(s)
        if n == 0:
            return [""]
        if s in self.d:
            return self.d[s]
        res = []
        for i in range(n - 1, -1, -1):
            suffix = s[i:]
            if suffix not in self.words:
                continue
            nxts = self.find(s[:i])
            for w in nxts:
                if len(w) == 0:
                    res.append(suffix)
                else:
                    res.append(w + ' ' + suffix)
        self.d[s] = res
        return res
        
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: List[str]
        """
        for w in wordDict:
            self.words.add(w)
        return self.find(s)
    
