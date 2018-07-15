# -*- coding:utf-8 -*-


# Given two integer arrays A and B, return the maximum length of an subarray that appears in both arrays.
#
# Example 1:
#
# Input:
# A: [1,2,3,2,1]
# B: [3,2,1,4,7]
# Output: 3
# Explanation: 
# The repeated subarray with maximum length is [3, 2, 1].
#
#
#
# Note:
#
# 1 <= len(A), len(B) <= 1000
# 0 <= A[i], B[i] < 100
#
#


class Solution(object):
    def findLength(self, A, B):
        """
        :type A: List[int]
        :type B: List[int]
        :rtype: int
        """
        na, nb = len(A), len(B)
        dp = [[0 for _ in range(nb + 1)] for _ in range(na + 1)]
        res = 0
        for i in range(1, na + 1):
            for j in range(1, nb + 1):
                if A[i - 1] == B[j - 1]:
                    dp[i][j] = 1 + dp[i - 1][j - 1]
                    res = max(res, dp[i][j])
        return res
        
