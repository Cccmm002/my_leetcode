# -*- coding:utf-8 -*-


# Given a sorted array of integers nums and integer values a, b and c.  Apply a function of the form f(x) = ax2 + bx + c to each element x in the array. 
#
# The returned array must be in sorted order.
#
# Expected time complexity: O(n)
#
# Example:
#
# nums = [-4, -2, 2, 4], a = 1, b = 3, c = 5,
#
# Result: [3, 9, 15, 33]
#
# nums = [-4, -2, 2, 4], a = -1, b = 3, c = 5
#
# Result: [-23, -5, 1, 7]
#
#
#
# Credits:Special thanks to @elmirap for adding this problem and creating all test cases.


class Solution(object):
    def sortTransformedArray(self, nums, a, b, c):
        """
        :type nums: List[int]
        :type a: int
        :type b: int
        :type c: int
        :rtype: List[int]
        """
        n = len(nums)
        fx = lambda x: a*x*x + b*x + c
        if a == 0:
            res = list(map(fx, nums))
            if b > 0: return res
            else: return res[::-1]
        mid = 0 - float(b)/float(2*a)
        left = []
        right = []
        for i in range(n):
            cur = fx(nums[i]);
            if (nums[i] <= mid):
                left.append(cur)
            else:
                right.append(cur)
        if a > 0:
            left = left[::-1]
        else:
            right = right[::-1]
        res = []
        pl = 0
        pr = 0
        while pl < len(left) or pr < len(right):
            if pl == len(left) or (pr < len(right) and left[pl] >= right[pr]):
                res.append(right[pr])
                pr += 1
            elif pr == len(right) or (pl < len(left) and left[pl] < right[pr]):
                res.append(left[pl])
                pl += 1
        return res
    
