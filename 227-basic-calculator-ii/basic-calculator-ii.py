# -*- coding:utf-8 -*-


# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
#
# Example 1:
#
#
# Input: "3+2*2"
# Output: 7
#
#
# Example 2:
#
#
# Input: " 3/2 "
# Output: 1
#
# Example 3:
#
#
# Input: " 3+5 / 2 "
# Output: 5
#
#
# Note:
#
#
# 	You may assume that the given expression is always valid.
# 	Do not use the eval built-in library function.
#
#


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s = s.replace(' ', '')
        n = len(s)
        res, prev = 0, 0
        sign = '+'
        p = 0
        while p < n:
            cur = 0
            while p < n and s[p].isdigit():
                cur = cur*10 + int(s[p])
                p += 1
            if sign == '+':
                res += prev
                prev = cur
            elif sign == '-':
                res += prev
                prev = -cur
            elif sign == '*':
                prev *= cur
            elif sign == '/':
                temp = abs(prev) // cur
                if prev < 0:
                    prev = -temp
                else:
                    prev = temp
            if p < n and (s[p] == '+' or s[p] == '-' or s[p] == '*' or s[p] == '/'):
                sign = s[p]
            p += 1
        res += prev
        return res
                
