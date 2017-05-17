# -*- coding:utf-8 -*-


# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
#
# You may assume that the given expression is always valid.
#
# Some examples:
#
# "1 + 1" = 2
# " 2-1 + 2 " = 3
# "(1+(4+5+2)-3)+(6+8)" = 23
#
#
#
#
# Note: Do not use the eval built-in library function.


class Solution(object):
    def evaluate(self, stack, start, end):
        # print(str(stack) + ' ' + str(start) + ' ' + str(end))
        res = 0
        prev = None
        for i in range(start, end+1):
            if stack[i] == '+':
                prev = '+'
            elif stack[i] == '-':
                prev = '-'
            elif prev is None or prev == '+':
                res += stack[i]
            elif prev == '-':
                res = res - stack[i]
        stack = stack[0:start]
        if len(stack) > 0:
            stack.pop()
        stack.append(res)
        return stack
        
        
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        total_len = len(s)
        stack = []
        cur_num = None
        for i in range(total_len):
            if s[i] >= '0' and s[i] <= '9':
                if cur_num is None:
                    cur_num = int(s[i])
                else:
                    cur_num = cur_num*10 + int(s[i])
            else:
                if cur_num is not None:
                    stack.append(cur_num)
                    cur_num = None
                if s[i] == ' ':
                    continue
                if s[i] == '(':
                    stack.append('(')
                elif s[i] == ')':
                    start = len(stack)-1
                    while stack[start] != '(':
                        start = start - 1
                    stack = self.evaluate(stack,start+1,len(stack)-1)
                elif s[i] == '+' or s[i] == '-':
                    stack.append(s[i])
        if cur_num is not None:
            stack.append(cur_num)
        stack = self.evaluate(stack, 0, len(stack)-1)
        return stack[0]
                
