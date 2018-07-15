# -*- coding:utf-8 -*-


# Given a string representing an expression of fraction addition and subtraction, you need to return the calculation result in string format. The final result should be irreducible fraction. If your final result is an integer, say 2, you need to change it to the format of fraction that has denominator 1. So in this case, 2 should be converted to 2/1.
#
# Example 1:
#
# Input:"-1/2+1/2"
# Output: "0/1"
#
#
#
# Example 2:
#
# Input:"-1/2+1/2+1/3"
# Output: "1/3"
#
#
#
# Example 3:
#
# Input:"1/3-1/2"
# Output: "-1/6"
#
#
#
# Example 4:
#
# Input:"5/3+1/3"
# Output: "2/1"
#
#
#
# Note:
#
# The input string only contains '0' to '9', '/', '+' and '-'. So does the output.
# Each fraction (input and output) has format ±numerator/denominator. If the first input fraction or the output is positive, then '+' will be omitted.
# The input only contains valid irreducible fractions, where the numerator and denominator of each fraction will always be in the range [1,10]. If the denominator is 1, it means this fraction is actually an integer in a fraction format defined above. 
# The number of given fractions will be in the range [1,10].
# The numerator and denominator of the final result are guaranteed to be valid and in the range of 32-bit int.
#
#


class Solution(object):
    def parsing(self, expression):
        tmp = expression.split('+')
        res = []
        for s in tmp:
            sa = s.split('-')
            for i in range(len(sa)):
                if sa[i] == '':
                    continue
                f = sa[i].split('/')
                minus = i == 0
                t = [minus, int(f[0]), int(f[1])]
                res.append(t)
        return res
        
    def gcd(self, a, b):
        while b != 0:
            t = b
            b = a % b
            a = t
        return a
        
    def lcm(self, arr):
        res = 1
        for n in arr:
            res = (res*n)/self.gcd(res, n)
        return res
        
    def fractionAddition(self, expression):
        """
        :type expression: str
        :rtype: str
        """
        fractions = self.parsing(expression)
        denarr = [f[2] for f in fractions]
        lcm = self.lcm(denarr)
        for i in range(len(fractions)):
            yz = lcm/fractions[i][2]
            fractions[i][1] = yz*fractions[i][1]
            fractions[i][2] = lcm
        num = 0
        den = lcm
        for f in fractions:
            if f[0]:
                num += f[1]
            else:
                num -= f[1]
        if num == 0:
            return "0/1"
        m = (num > 0) == (den > 0)
        num = abs(num)
        den = abs(den)
        g = self.gcd(num, den)
        num = num/g
        den = den/g
        res = '' if m else '-'
        res += str(num) + '/' + str(den)
        return res
        
