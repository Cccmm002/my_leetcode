# -*- coding:utf-8 -*-


# Validate if a given string is numeric.
#
#
# Some examples:
# "0" => true
# "   0.1  " => true
# "abc" => false
# "1 a" => false
# "2e10" => true
#
#
# Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
#
#
#
# Update (2015-02-10):
# The signature of the C++ function had been updated. If you still see your function signature accepts a const char * argument, please click the reload button  to reset your code definition.


class Solution(object):
    def isInteger(self, s):
        if len(s) == 0:
            return False
        for c in s:
            cur = ord(c)
            if cur < 48 or cur > 57:
                return False
        return True
        
    def isDecimal(self, s):
        if len(s) == 0:
            return False
        if s[0] == '-' or s[0] == '+':
            s = s[1:]
        if '.' in s:
            idx = s.index('.')
            a = s[:idx]
            b = s[idx+1:]
            if a == '':
                return self.isInteger(b)
            elif b == '':
                return self.isInteger(a)
            else:
                return self.isInteger(a) and self.isInteger(b)
        else:
            return self.isInteger(s)
        
    def isNumber(self, s):
        """
        :type s: str
        :rtype: bool
        """
        s = s.strip()
        if 'e' in s:
            idx = s.index('e')
            a = s[:idx]
            b = s[idx+1:]
            if len(b) == 0:
                return False
            if b[0] == '-' or b[0] == '+':
                b = b[1:]
            return self.isDecimal(a) and self.isInteger(b)
        else:
            return self.isDecimal(s)
        
