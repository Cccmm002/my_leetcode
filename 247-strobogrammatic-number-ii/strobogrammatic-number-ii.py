# -*- coding:utf-8 -*-


# A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
#
# Find all strobogrammatic numbers that are of length = n.
#
# Example:
#
#
# Input:  n = 2
# Output: ["11","69","88","96"]
#
#


class Solution(object):
    def find(self, n):
        if n == 0:
            return ['']
        elif n == 1:
            return ['0', '1', '8']
        else:
            prev = self.find(n - 2)
            res = []
            for s in prev:
                res.append('0' + s + '0')
                res.append('1' + s + '1')
                res.append('6' + s + '9')
                res.append('8' + s + '8')
                res.append('9' + s + '6')
        return res
    
    def findStrobogrammatic(self, n):
        """
        :type n: int
        :rtype: List[str]
        """
        rough = self.find(n)
        if n == 1:
            return rough
        res = []
        for r in rough:
            if r[0] != '0':
                res.append(r)
        return res
    
