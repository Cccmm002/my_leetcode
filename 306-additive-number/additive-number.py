# -*- coding:utf-8 -*-


# Additive number is a string whose digits can form additive sequence.
#
# A valid additive sequence should contain at least three numbers. Except for the first two numbers, each subsequent number in the sequence must be the sum of the preceding two.
#
#
# For example:
# "112358" is an additive number because the digits can form an additive sequence: 1, 1, 2, 3, 5, 8.
# 1 + 1 = 2, 1 + 2 = 3, 2 + 3 = 5, 3 + 5 = 8
# "199100199" is also an additive number, the additive sequence is: 1, 99, 100, 199.
# 1 + 99 = 100, 99 + 100 = 199
#
#
#
# Note: Numbers in the additive sequence cannot have leading zeros, so sequence 1, 2, 03 or 1, 02, 3 is invalid.
#
#
# Given a string containing only digits '0'-'9', write a function to determine if it's an additive number.
#
#
# Follow up:
# How would you handle overflow for very large input integers?
#
#
# Credits:Special thanks to @jeantimex for adding this problem and creating all test cases.


class Solution(object):
    def check(self, snum, first, second):
        if len(snum) <= 0:
            return False
        a = first
        b = second
        s = snum
        while len(s) > 0:
            c = a + b
            sc = str(c)
            lc = len(sc)
            if lc > len(s):
                return False
            if sc != s[:lc]:
                return False
            s = s[lc:]
            a = b
            b = c
        return True
        
    
    def isAdditiveNumber(self, num):
        """
        :type num: str
        :rtype: bool
        """
        l = len(num)
        if l <= 2:
            return False
        loop_upper = 2 if num[0] == '0' else min(l/2+2, l)
        for i in range(1, loop_upper):
            first = int(num[:i])
            if num[i] == '0':
                second = 0
                if self.check(num[i+1:], first, second):
                    return True
            else:
                for j in range(i+1, l+1):
                    second = int(num[i:j])
                    ns = num[j:]
                    if self.check(ns, first, second):
                        return True
        return False
        
