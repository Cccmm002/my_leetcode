# -*- coding:utf-8 -*-


#
# Given a non-negative integer, you could swap two digits at most once to get the maximum valued number. Return the maximum valued number you could get.
#
#
# Example 1:
#
# Input: 2736
# Output: 7236
# Explanation: Swap the number 2 and the number 7.
#
#
#
# Example 2:
#
# Input: 9973
# Output: 9973
# Explanation: No swap.
#
#
#
#
# Note:
#
# The given number is in the range [0, 108]
#
#


class Solution(object):
    def getMax(self, digits):
        if len(digits) == 0: return []
        m = max(digits)
        if digits[-1] == m:
            return self.getMax(digits[:-1]) + [m]
        res = digits[:]
        i = digits.index(m)
        res[i] = digits[-1]
        res[-1] = m
        return res
        
    def maximumSwap(self, num):
        """
        :type num: int
        :rtype: int
        """
        n = num
        digits = []
        while n > 0:
            digits.append(n % 10)
            n /= 10
        rd = self.getMax(digits)
        res = 0
        for i in range(len(rd)):
            res += rd[i] * (10**i)
        return res
        
