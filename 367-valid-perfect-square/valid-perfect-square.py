# -*- coding:utf-8 -*-


# Given a positive integer num, write a function which returns True if num is a perfect square else False.
#
#
# Note: Do not use any built-in library function such as sqrt.
#
#
# Example 1:
#
# Input: 16
# Returns: True
#
#
#
# Example 2:
#
# Input: 14
# Returns: False
#
#
#
# Credits:Special thanks to @elmirap for adding this problem and creating all test cases.


class Solution(object):
    def isPerfectSquare(self, num):
        """
        :type num: int
        :rtype: bool
        """
        b=0
        e=num
        while b<e:
            m=(b+e)//2
            c=m*m
            if c==num:
                return True
            elif c>num:
                e=m-1
            else:
                b=m+1
        if b*b==num:
            return True
        else:
            return False
