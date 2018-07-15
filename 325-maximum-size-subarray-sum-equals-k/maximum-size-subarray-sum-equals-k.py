# -*- coding:utf-8 -*-


# Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.
#
# Note:
# The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.
#
# Example 1:
#
#
# Input: nums = [1, -1, 5, -2, 3], k = 3
# Output: 4 
# Explanation: The subarray [1, -1, 5, -2] sums to 3 and is the longest.
#
#
# Example 2:
#
#
# Input: nums = [-2, -1, 2, 1], k = 1
# Output: 2 
# Explanation: The subarray [-1, 2] sums to 1 and is the longest.
#
# Follow Up:
# Can you do it in O(n) time?
#


class Solution(object):
    def maxSubArrayLen(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: int
        """
        l = len(nums)
        if l == 0: return 0
        sums = [nums[0]]
        for i in range(1, l):
            sums.append(sums[i - 1] + nums[i])
        d = {0 : -1}
        res = 0
        for i in range(l):
            cur = sums[i]     # cur - early = k  ==>  early = cur - k
            if cur - k in d:
                res = max(res, i - d[cur - k])
            if cur not in d:
                d[cur] = i
        return res
        
