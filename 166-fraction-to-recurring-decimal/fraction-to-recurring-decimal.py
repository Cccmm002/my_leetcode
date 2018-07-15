# -*- coding:utf-8 -*-


# Given two integers representing the numerator and denominator of a fraction, return the fraction in string format.
#
# If the fractional part is repeating, enclose the repeating part in parentheses.
#
# Example 1:
#
#
# Input: numerator = 1, denominator = 2
# Output: "0.5"
#
#
# Example 2:
#
#
# Input: numerator = 2, denominator = 1
# Output: "2"
#
# Example 3:
#
#
# Input: numerator = 2, denominator = 3
# Output: "0.(6)"
#
#


class Solution(object):
    def fractionToDecimal(self, numerator, denominator):
        """
        :type numerator: int
        :type denominator: int
        :rtype: str
        """
        if numerator == 0: return "0"
        intPart = numerator / denominator
        decimal = ""
        d = dict()
        negative = (numerator < 0) != (denominator < 0)
        numerator = abs(numerator)
        denominator = abs(denominator)
        reminder = numerator % denominator
        if reminder == 0: return str(intPart)
        while reminder != 0:
            d[reminder] = len(decimal)
            cur = str((reminder*10)/denominator)
            decimal += cur
            nr = (reminder*10)%denominator
            if nr in d:
                decimal = decimal[:d[nr]] + '(' + decimal[d[nr]:] + ')'
                break
            reminder = nr
        sign = '-' if negative else ""
        return sign + str(numerator / denominator) + '.' + decimal
    
