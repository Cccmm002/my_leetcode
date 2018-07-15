# -*- coding:utf-8 -*-


# Given an array of strings, group anagrams together.
#
# Example:
#
#
# Input: ["eat", "tea", "tan", "ate", "nat", "bat"],
# Output:
# [
#   ["ate","eat","tea"],
#   ["nat","tan"],
#   ["bat"]
# ]
#
# Note:
#
#
# 	All inputs will be in lowercase.
# 	The order of your output does not matter.
#
#


class Solution(object):
    def groupAnagrams(self, strs):
        """
        :type strs: List[str]
        :rtype: List[List[str]]
        """
        d = dict()
        for s in strs:
            ss = ''.join(sorted(s))
            if ss in d:
                d[ss].append(s)
            else:
                d[ss] = [s]
        res = []
        for k in d:
            res.append(sorted(d[k]))
        return res
    
