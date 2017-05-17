# -*- coding:utf-8 -*-


# All DNA is composed of a series of nucleotides abbreviated as A, C, G, and T, for example: "ACGAATTCCG". When studying DNA, it is sometimes useful to identify repeated sequences within the DNA.
#
# Write a function to find all the 10-letter-long sequences (substrings) that occur more than once in a DNA molecule.
#
#
# For example,
#
# Given s = "AAAAACCCCCAAAAACCCCCCAAAAAGGGTTT",
#
# Return:
# ["AAAAACCCCC", "CCCCCAAAAA"].


class Solution(object):
    def findRepeatedDnaSequences(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        l = len(s)
        ht = set()
        res = set()
        for i in range(l-9):
            ss = s[i:i+10]
            if ss in ht:
                res.add(ss)
            else:
                ht.add(ss)
        return list(res)
