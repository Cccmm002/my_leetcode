# -*- coding:utf-8 -*-


# Given an integer array, your task is to find all the different possible increasing subsequences of the given array, and the length of an increasing subsequence should be at least 2 .
#
#
# Example:
#
# Input: [4, 6, 7, 7]
# Output: [[4, 6], [4, 7], [4, 6, 7], [4, 6, 7, 7], [6, 7], [6, 7, 7], [7,7], [4,7,7]]
#
#
#
# Note:
#
# The length of the given array will not exceed 15.
# The range of integer in the given array is [-100,100].
# The given array may contain duplicates, and two equal integers should also be considered as a special case of increasing sequence.


class Solution(object):
    def findSubsequences(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        current = []
        res = set()
        numlen = len(nums)
        
        def helper(pos):
            existed = len(current)
            if pos >= numlen:
                if existed >= 2:
                    res.add(tuple(current[:]))
                return
            if existed == 0 or current[existed - 1] <= nums[pos]:
                current.append(nums[pos])
                helper(pos + 1)
                current.pop()
            helper(pos + 1)
        
        helper(0)
        rl = list(res)
        rl = list(map(lambda x: list(x), rl))
        return list(rl)
        
