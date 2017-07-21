# -*- coding:utf-8 -*-


# Given a string, we can "shift" each of its letter to its successive letter, for example: "abc" -> "bcd". We can keep "shifting" which forms the sequence:
# "abc" -> "bcd" -> ... -> "xyz"
#
# Given a list of strings which contains only lowercase alphabets, group all strings that belong to the same shifting sequence.
#
# For example, given: ["abc", "bcd", "acef", "xyz", "az", "ba", "a", "z"], 
# A solution is:
#
# [
#   ["abc","bcd","xyz"],
#   ["az","ba"],
#   ["acef"],
#   ["a","z"]
# ]


class Solution(object):
    def groupStrings(self, strings):
        """
        :type strings: List[str]
        :rtype: List[List[str]]
        """
        d = dict()
        for s in strings:
            n = len(s)
            l = [0 for i in range(n)]
            diff = ord(s[0]) - ord('a')
            l[0] = 0
            for i in range(1, n):
                l[i] = ord(s[i]) - ord('a') - diff
                if l[i] < 0:
                    l[i] += 26
            t = tuple(l)
            if t in d:
                d[t].append(s)
            else:
                d[t] = [s]
        res = []
        for k in d:
            res.append(d[k])
        return res
