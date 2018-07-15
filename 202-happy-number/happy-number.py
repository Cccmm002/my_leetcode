# -*- coding:utf-8 -*-


# Write an algorithm to determine if a number is "happy".
#
# A happy number is a number defined by the following process: Starting with any positive integer, replace the number by the sum of the squares of its digits, and repeat the process until the number equals 1 (where it will stay), or it loops endlessly in a cycle which does not include 1. Those numbers for which this process ends in 1 are happy numbers.
#
# Example: 
#
#
# Input: 19
# Output: true
# Explanation: 
# 12 + 92 = 82
# 82 + 22 = 68
# 62 + 82 = 100
# 12 + 02 + 02 = 1
#
#


class Solution(object):
    def happy(self, n):
        res=0
        while n>0:
            c=n%10
            res+=c*c
            n=n//10
        return res
    def isHappy(self, n):
        """
        :type n: int
        :rtype: bool
        """
        s=set()
        cur=n
        while cur!=1:
            if cur in s:
                return False
            s.add(cur)
            cur=self.happy(cur)
        return True
