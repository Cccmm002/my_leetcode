# -*- coding:utf-8 -*-


# There is a garden with N slots. In each slot, there is a flower. The N flowers will bloom one by one in N days. In each day, there will be exactly one flower blooming and it will be in the status of blooming since then.
#
#
#
# Given an array flowers consists of number from 1 to N. Each number in the array represents the place where the flower will open in that day.
#
#
#
# For example, flowers[i] = x means that the unique flower that blooms at day i will be at position x, where i and x will be in the range from 1 to N.
#
#
#
# Also given an integer k, you need to output in which day there exists two flowers in the status of blooming, and also the number of flowers between them is k and these flowers are not blooming.
#
#
#
# If there isn't such day, output -1.
#
#
# Example 1:
#
# Input: 
# flowers: [1,3,2]
# k: 1
# Output: 2
# Explanation: In the second day, the first and the third flower have become blooming.
#
#
#
# Example 2:
#
# Input: 
# flowers: [1,2,3]
# k: 1
# Output: -1
#
#
#
#
# Note:
#
# The given array will be in the range [1, 20000].


class Solution(object):
    def kEmptySlots(self, flowers, k):
        """
        :type flowers: List[int]
        :type k: int
        :rtype: int
        """
        n = len(flowers)
        days = [0 for _ in range(n)]
        for i in range(n):
            days[flowers[i] - 1] = i + 1
        left, i, right = 0, 0, k + 1
        res = None
        while right < n:
            if days[i] < days[left] or days[i] <= days[right]:
                if i == right:
                    r = max(days[left], days[right])
                    if res is None:
                        res = r
                    else:
                        res = min(res, r)
                left = i
                right = left + k + 1
            i += 1
        if res is None:
            return -1
        else:
            return res
        
