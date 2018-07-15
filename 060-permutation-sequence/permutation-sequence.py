# -*- coding:utf-8 -*-


# The set [1,2,3,...,n] contains a total of n! unique permutations.
#
# By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
#
#
# 	"123"
# 	"132"
# 	"213"
# 	"231"
# 	"312"
# 	"321"
#
#
# Given n and k, return the kth permutation sequence.
#
# Note:
#
#
# 	Given n will be between 1 and 9 inclusive.
# 	Given k will be between 1 and n! inclusive.
#
#
# Example 1:
#
#
# Input: n = 3, k = 3
# Output: "213"
#
#
# Example 2:
#
#
# Input: n = 4, k = 9
# Output: "2314"
#
#


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
        
