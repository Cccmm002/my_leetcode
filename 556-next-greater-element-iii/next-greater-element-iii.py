# -*- coding:utf-8 -*-


# Given a positive 32-bit integer n, you need to find the smallest 32-bit integer which has exactly the same digits existing in the integer n and is greater in value than n. If no such positive 32-bit integer exists, you need to return -1.
#
# Example 1:
#
#
# Input: 12
# Output: 21
#
#
#  
#
# Example 2:
#
#
# Input: 21
# Output: -1
#
#
#  
#


class Solution(object):
    def nextGreaterElement(self, n):
        """
        :type n: int
        :rtype: int
        """
        word = list(str(n))
        l = len(word)
        for i in range(l - 2, -1, -1):
            if word[i] < word[i + 1]:
                tl = i + 1
                for k in range(i + 2,l):
                    if word[tl] > word[k] and word[k] > word[i]:
                        tl = k
                t = word[tl]
                word[tl] = word[i]
                word[i] = t
                word[i + 1:] = sorted(word[i + 1:])
                break
        s = ''.join(word)
        if s == str(n): return -1
        res = int(s)
        if res > 2147483647:
            return -1
        return res
    
