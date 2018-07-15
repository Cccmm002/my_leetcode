# -*- coding:utf-8 -*-


#
# Given two arrays, write a function to compute their intersection.
#
#
# Example:
# Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
#
#
# Note:
#
# Each element in the result must be unique.
# The result can be in any order.
#
#


class Solution(object):
    def intersection(self, nums1, nums2):
        """
        :type nums1: List[int]
        :type nums2: List[int]
        :rtype: List[int]
        """
        s = set()
        for num in nums1:
            s.add(num)
        res = set()
        for num in nums2:
            if num in s:
                res.add(num)
        return list(res)
    
