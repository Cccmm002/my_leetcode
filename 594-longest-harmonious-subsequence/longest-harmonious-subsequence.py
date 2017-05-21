# -*- coding:utf-8 -*-


# We define a harmonious array is an array where the difference between its maximum value and its minimum value is exactly 1.
#
# Now, given an integer array, you need to find the length of its longest harmonious subsequence among all its possible subsequences.
#
# Example 1:
#
# Input: [1,3,2,2,5,2,3,7]
# Output: 5
# Explanation: The longest harmonious subsequence is [3,2,2,2,3].
#
#
#
# Note:
# The length of the input array will not exceed 20,000.


class Solution(object):
    def findLHS(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        d = dict()
        l = len(nums)
        if l == 0:
            return 0
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        res = 0
        for key in d:
            next = key + 1
            if next in d:
                res = max(res, d[next] + d[key])
        return res
        
