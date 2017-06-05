# -*- coding:utf-8 -*-


# The set [1,2,3,&#8230;,n] contains a total of n! unique permutations.
#
# By listing and labeling all of the permutations in order,
# We get the following sequence (ie, for n = 3):
#
# "123"
# "132"
# "213"
# "231"
# "312"
# "321"
#
#
#
# Given n and k, return the kth permutation sequence.
#
# Note: Given n will be between 1 and 9 inclusive.


class Solution(object):
    def calc(self, n, k, l):
        if n == 0: return []
        para = 1
        for i in range(1, n):
            para = para * i
        i = (k - 1)/para + 1
        res = [l[i - 1]]
        nl = l[:i-1] + l[i:]
        next = self.calc(n - 1, k - para*(i - 1), nl)
        return res + next
        
    def getPermutation(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        l = [i + 1 for i in range(n)]
        rl = self.calc(n, k, l)
        for i in range(len(rl)):
            rl[i] = str(rl[i])
        return ''.join(rl)
        
