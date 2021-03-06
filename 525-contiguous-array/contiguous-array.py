# -*- coding:utf-8 -*-


# Given a binary array, find the maximum length of a contiguous subarray with equal number of 0 and 1. 
#
#
# Example 1:
#
# Input: [0,1]
# Output: 2
# Explanation: [0, 1] is the longest contiguous subarray with equal number of 0 and 1.
#
#
#
# Example 2:
#
# Input: [0,1,0]
# Output: 2
# Explanation: [0, 1] (or [1, 0]) is a longest contiguous subarray with equal number of 0 and 1.
#
#
#
# Note:
# The length of the given binary array will not exceed 50,000.
#


class Solution(object):
    def findMaxLength(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        d = dict()
        d[0] = 0
        cur = 0
        res = 0
        for i in range(len(nums)):
            if nums[i] == 0:
                cur -= 1
            else:
                cur += 1
            if cur in d:
                res = max(res, i + 1 - d[cur])
            else:
                d[cur] = i + 1
        return res
        
