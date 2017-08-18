# -*- coding:utf-8 -*-


# Given a non-empty string containing an out-of-order English representation of digits 0-9, output the digits in ascending order.
#
# Note:
#
# Input contains only lowercase English letters.
# Input is guaranteed to be valid and can be transformed to its original digits. That means invalid inputs such as "abc" or "zerone" are not permitted.
# Input length is less than 50,000.
#
#
#
# Example 1:
#
# Input: "owoztneoer"
#
# Output: "012"
#
#
#
# Example 2:
#
# Input: "fviefuro"
#
# Output: "45"


class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        digits = dict()
        for i in range(10):
            digits[i] = 0
        chars = dict()
        for c in s:
            if c in chars:
                chars[c] += 1
            else:
                chars[c] = 1
        for c in chars:
            if chars[c] == 0: continue
            if c == 'z':
                digits[0] += chars[c]
                chars['o'] -= chars[c]
                chars[c] = 0
            elif c == 'w':
                digits[2] += chars[c]
                chars['t'] -= chars[c]
                chars['o'] -= chars[c]
                chars[c] = 0
            elif c == 'u':
                digits[4] += chars[c]
                chars['f'] -= chars[c]
                chars['o'] -= chars[c]
                chars[c] = 0
            elif c == 'x':
                digits[6] += chars[c]
                chars['s'] -= chars[c]
                chars['i'] -= chars[c]
                chars[c] = 0
            elif c == 'g':
                digits[8] += chars[c]
                chars['t'] -= chars[c]
                chars['i'] -= chars[c]
        for c in chars:
            if chars[c] == 0: continue
            if c == 'o':
                digits[1] += chars[c]
            elif c == 't':
                digits[3] += chars[c]
            elif c == 'f':
                digits[5] += chars[c]
                chars['i'] -= chars[c]
            elif c == 's':
                digits[7] += chars[c]
        for c in chars:
            if chars[c] == 0: continue
            if c == 'i':
                digits[9] += chars[c]
        res = ""
        for i in range(10):
            res += str(i)*digits[i]
        return res
                
