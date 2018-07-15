# -*- coding:utf-8 -*-


# Given an array of n positive integers and a positive integer s, find the minimal length of a contiguous subarray of which the sum ≥ s. If there isn't one, return 0 instead.
#
# Example: 
#
#
# Input: s = 7, nums = [2,3,1,2,4,3]
# Output: 2
# Explanation: the subarray [4,3] has the minimal length under the problem constraint.
#
# Follow up:
#
# If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log n). 
#


class Solution(object):
    def minSubArrayLen(self, s, nums):
        """
        :type s: int
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        if n == 0:
            return 0
        left, right = 0, 0
        res, sums = float('inf'), nums[0]
        while left < n:
            while right < n:
                if sums >= s:
                    res = min(res, right - left + 1)
                    break
                right += 1
                if right < n:
                    sums += nums[right]
            sums -= nums[left]
            left += 1
        if res < float('inf'):
            return res
        else:
            return 0
                    
