# -*- coding:utf-8 -*-


# Given a list of words, we may encode it by writing a reference string S and a list of indexes A.
#
# For example, if the list of words is ["time", "me", "bell"], we can write it as S = "time#bell#" and indexes = [0, 2, 5].
#
# Then for each index, we will recover the word by reading from the reference string from that index until we reach a "#" character.
#
# What is the length of the shortest reference string S possible that encodes the given words?
#
# Example:
#
#
# Input: words = ["time", "me", "bell"]
# Output: 10
# Explanation: S = "time#bell#" and indexes = [0, 2, 5].
#
#
# Note:
#
#
# 	1 <= words.length <= 2000.
# 	1 <= words[i].length <= 7.
# 	Each word has only lowercase letters.
#
#


class Solution(object):
    def minimumLengthEncoding(self, words):
        """
        :type words: List[str]
        :rtype: int
        """
        sw = sorted(words, cmp=lambda x, y:-cmp(len(x), len(y)))
        res_pool = set()
        suffix = set()
        for w in sw:
            if w in suffix:
                continue
            res_pool.add(w)
            n = len(w)
            for i in range(n):
                suffix.add(w[i:])
        res = 0
        for w in res_pool:
            res += len(w)
        res += len(res_pool)
        return res
    
