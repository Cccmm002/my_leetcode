# -*- coding:utf-8 -*-


#
# There is a box protected by a password.  The password is n digits, where each letter can be one of the first k digits 0, 1, ..., k-1.
#
# You can keep inputting the password, the password will automatically be matched against the last n digits entered.
#
# For example, assuming the password is "345", I can open it when I type "012345", but I enter a total of 6 digits.
#
# Please return any string of minimum length that is guaranteed to open the box after the entire string is inputted.
#
#
# Example 1:
#
# Input: n = 1, k = 2
# Output: "01"
# Note: "10" will be accepted too.
#
#
#
# Example 2:
#
# Input: n = 2, k = 2
# Output: "00110"
# Note: "01100", "10011", "11001" will be accepted too.
#
#
#
# Note:
#
# n will be in the range [1, 4].
# k will be in the range [1, 10].
# k^n will be at most 4096.
#
#


class Solution(object):
    def __init__(self):
        self.existed = set()
        self.total = 0
        self.n = 0
        self.k = 0

    def solve(self, prev):
        if len(self.existed) == self.total:
            return ""
        for i in range(self.k):
            nxt = prev + str(i)
            if nxt in self.existed:
                continue
            self.existed.add(nxt)
            after = self.solve(nxt[1:])
            if after is None:
                self.existed.remove(nxt)
            else:
                return str(i) + after
        return None
            
    
    def crackSafe(self, n, k):
        """
        :type n: int
        :type k: int
        :rtype: str
        """
        self.total = pow(k, n)
        self.n = n
        self.k = k
        beginning = '0' * n
        self.existed.add(beginning)
        return beginning + self.solve(beginning[1:])
    
