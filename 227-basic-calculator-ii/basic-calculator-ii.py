# -*- coding:utf-8 -*-


# Implement a basic calculator to evaluate a simple expression string.
#
# The expression string contains only non-negative integers, +, -, *, / operators and empty spaces  . The integer division should truncate toward zero.
#
# You may assume that the given expression is always valid.
#
# Some examples:
#
# "3+2*2" = 7
# " 3/2 " = 1
# " 3+5 / 2 " = 5
#
#
#
#
# Note: Do not use the eval built-in library function.
#
#
# Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution(object):
    def calculate(self, s):
        """
        :type s: str
        :rtype: int
        """
        s += ' '
        total_len = len(s)
        stack = []
        cur_num = None
        prevsym = None
        for i in range(total_len):
            if s[i]>='0' and s[i]<='9':
                if cur_num is None:
                    cur_num = int(s[i])
                else:
                    cur_num = cur_num*10 + int(s[i])
            else:
                if cur_num is not None:
                    if prevsym == '*':
                        p = stack.pop()
                        stack.append(p*cur_num)
                    elif prevsym == '/':
                        p = stack.pop()
                        stack.append(p/cur_num)
                    else:
                        stack.append(cur_num)
                    cur_num = None
                if s[i] == ' ':
                    continue
                if s[i] == '+' or s[i] == '-':
                    prevsym = s[i]
                    stack.append(s[i])
                elif s[i] == '*' or s[i] == '/':
                    prevsym = s[i]
            # print(stack)
        res = 0
        prevsym = '+'
        for i in range(len(stack)):
            if stack[i] == '+' or stack[i] == '-':
                prevsym = stack[i]
            else:
                if prevsym == '+':
                    res += stack[i]
                else:
                    res = res - stack[i]
        return res
                    
