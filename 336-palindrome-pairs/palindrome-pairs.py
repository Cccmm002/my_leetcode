# -*- coding:utf-8 -*-


# Given a list of unique words, find all pairs of distinct indices (i, j) in the given list, so that the concatenation of the two words, i.e. words[i] + words[j] is a palindrome.
#
#
#
#     Example 1:
#     Given words = ["bat", "tab", "cat"]
#     Return [[0, 1], [1, 0]]
#     The palindromes are ["battab", "tabbat"]
#
#
#     Example 2:
#     Given words = ["abcd", "dcba", "lls", "s", "sssll"]
#     Return [[0, 1], [1, 0], [3, 2], [2, 4]]
#     The palindromes are ["dcbaabcd", "abcddcba", "slls", "llssssll"]
#
#
# Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution(object):
    def isPalin(self, word):
        n = len(word)
        begin = 0
        end = n - 1
        while begin < end:
            if word[begin] != word[end]:
                return False
            begin += 1
            end -= 1
        return True
        
    def palindromePairs(self, words):
        """
        :type words: List[str]
        :rtype: List[List[int]]
        """
        n = len(words)
        if n == 0: return []
        d = dict()
        for i in range(n):
            if words[i] == '': continue
            d[words[i][::-1]] = i
        res = []
        for i in range(n):
            w = words[i]
            s = len(w)
            if s == 0:
                for j in range(n):
                    if words[j] == '': continue
                    if self.isPalin(words[j]):
                        res.append([i, j])
                        res.append([j, i])
            for j in range(s):
                left = w[:j]
                right = w[j:]
                if left in d and self.isPalin(right):
                    if i != d[left]:
                        res.append([i, d[left]])
                if right in d and self.isPalin(left):
                    if i != d[right]:
                        res.append([d[right], i])
        return res
        
