# -*- coding:utf-8 -*-


#
# Given a string containing only three types of characters: '(', ')' and '*', write a function to check whether this string is valid. We define the validity of a string by these rules:
#
# Any left parenthesis '(' must have a corresponding right parenthesis ')'.
# Any right parenthesis ')' must have a corresponding left parenthesis '('.
# Left parenthesis '(' must go before the corresponding right parenthesis ')'.
# '*' could be treated as a single right parenthesis ')' or a single left parenthesis '(' or an empty string.
# An empty string is also valid.
#
#
#
# Example 1:
#
# Input: "()"
# Output: True
#
#
#
# Example 2:
#
# Input: "(*)"
# Output: True
#
#
#
# Example 3:
#
# Input: "(*))"
# Output: True
#
#
#
# Note:
#
# The string size will be in the range [1, 100].
#
#


class Solution(object):
    def __init__(self):
        self.d = dict()
        
    def check(self, s):
        if s in self.d:
            return self.d[s]
        else:
            res = self._check(s)
            self.d[s] = res
            return res
        
    def _check(self, s):
        n = len(s)
        if n == 0: return True
        if n == 1: return s == '*'
        if s[0] == ')': return False
        for k in range(1, n):
            if s[k] == '(': continue
            r = self.check(s[1:k]) and self.check(s[k + 1:])
            if r: return True
        return False
        
    def checkValidString(self, s):
        return self.check(s)
    
