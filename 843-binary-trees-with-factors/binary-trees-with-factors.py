# -*- coding:utf-8 -*-


# Given an array of unique integers, each integer is strictly greater than 1.
#
# We make a binary tree using these integers and each number may be used for any number of times.
#
# Each non-leaf node's value should be equal to the product of the values of it's children.
#
# How many binary trees can we make?  Return the answer modulo 10 ** 9 + 7.
#
# Example 1:
#
#
# Input: A = [2, 4]
# Output: 3
# Explanation: We can make these trees: [2], [4], [4, 2, 2]
#
# Example 2:
#
#
# Input: A = [2, 4, 5, 10]
# Output: 7
# Explanation: We can make these trees: [2], [4], [5], [10], [4, 2, 2], [10, 2, 5], [10, 5, 2].
#
#  
#
# Note:
#
#
# 	1 <= A.length <= 1000.
# 	2 <= A[i] <= 10 ^ 9.
#
#


class Solution(object):
    def numFactoredBinaryTrees(self, A):
        """
        :type A: List[int]
        :rtype: int
        """
        n = len(A)
        res = [0 for _ in range(n)]
        A = sorted(A)
        s = dict()
        for i in range(n):
            res[i] = 1
            if i > 0:
                for j in range(i):
                    d = int(A[i]/A[j])
                    if A[i] != A[j]*d: continue
                    if d not in s: continue
                    res[i] += (res[j]*res[s[d]])%1000000007
            s[A[i]] = i
        return sum(res)%1000000007
    
