# -*- coding:utf-8 -*-


# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
#
# Example 1:
#
#
# Input: "1 + 1"
# Output: 2
#
#
# Example 2:
#
#
# Input: " 2-1 + 2 "
# Output: 3
#
# Example 3:
#
#
# Input: "(1+(4+5+2)-3)+(6+8)"
# Output: 23
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
        stack = []
        n = len(s)
        if n == 0: return 0
        current = 0
        plus = True
        p = 0
        while p < n:
            if s[p] == ' ':
                p += 1
                continue
            if s[p] == '(':
                stack.append((current, plus))
                current = 0
                plus = True
                p += 1
            elif s[p] == ')':
                prev = stack.pop()
                if prev[1]:
                    current = prev[0] + current
                else:
                    current = prev[0] - current
                p += 1
            elif s[p] == '+':
                plus = True
                p += 1
            elif s[p] == '-':
                plus = False
                p += 1
            else:
                np = p
                while np < n and s[np].isdigit():
                    np += 1
                add = int(s[p:np])
                if plus:
                    current += add
                else:
                    current -= add
                p = np
        return current
    
