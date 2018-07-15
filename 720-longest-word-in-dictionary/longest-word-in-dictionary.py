# -*- coding:utf-8 -*-


# Given a list of strings words representing an English Dictionary, find the longest word in words that can be built one character at a time by other words in words.  If there is more than one possible answer, return the longest word with the smallest lexicographical order.  If there is no answer, return the empty string.
#
# Example 1:
#
# Input: 
# words = ["w","wo","wor","worl", "world"]
# Output: "world"
# Explanation: 
# The word "world" can be built one character at a time by "w", "wo", "wor", and "worl".
#
#
#
# Example 2:
#
# Input: 
# words = ["a", "banana", "app", "appl", "ap", "apply", "apple"]
# Output: "apple"
# Explanation: 
# Both "apply" and "apple" can be built from other words in the dictionary. However, "apple" is lexicographically smaller than "apply".
#
#
#
# Note:
# All the strings in the input will only contain lowercase letters.
# The length of words will be in the range [1, 1000].
# The length of words[i] will be in the range [1, 30].
#


class Solution(object):
    def longestWord(self, words):
        """
        :type words: List[str]
        :rtype: str
        """
        s = set()
        len_dict = dict()
        for w in words:
            s.add(w)
            cur_len = len(w)
            if cur_len not in len_dict:
                len_dict[cur_len] = []
            len_dict[cur_len].append(w)
        for k in len_dict:
            len_dict[k].sort()
        keys = len_dict.keys()
        keys.sort(reverse=True)
        for i in range(len(keys)):
            for w in len_dict[keys[i]]:
                found = True
                for j in range(len(w) - 1, 0, -1):
                    if w[:j] not in s:
                        found = False
                        break
                if found:
                    return w
        return ""
    