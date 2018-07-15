# -*- coding:utf-8 -*-


#
# Given an array nums of integers, you can perform operations on the array.
#
# In each operation, you pick any nums[i] and delete it to earn nums[i] points.  After, you must delete every element equal to nums[i] - 1 or nums[i] + 1.
#
# You start with 0 points.  Return the maximum number of points you can earn by applying such operations.
#
#
# Example 1:
#
# Input: nums = [3, 4, 2]
# Output: 6
# Explanation: 
# Delete 4 to earn 4 points, consequently 3 is also deleted.
# Then, delete 2 to earn 2 points. 6 total points are earned.
#
#
#
# Example 2:
#
# Input: nums = [2, 2, 3, 3, 3, 4]
# Output: 9
# Explanation: 
# Delete 3 to earn 3 points, deleting both 2's and the 4.
# Then, delete 3 again to earn 3 points, and 3 again to earn 3 points.
# 9 total points are earned.
#
#
#
# Note:
# The length of nums is at most 20000.
# Each element nums[i] is an integer in the range [1, 10000].
#


class Solution(object):
    def deleteAndEarn(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        if len(nums) == 0:
            return 0
        counts = collections.Counter(nums)
        keys = sorted(counts)
        n = len(keys)
        arr = [0 for _ in range(n)]
        arr[0] = keys[0]*counts[keys[0]]
        for i in range(1, n):
            arr[i] = keys[i]*counts[keys[i]]
            if keys[i] - 1 == keys[i - 1]:
                if i - 2 >= 0:
                    arr[i] += arr[i - 2]
            else:
                arr[i] += arr[i - 1]
            if keys[i] - 1 == keys[i - 1]:
                another = keys[i - 1]*counts[keys[i - 1]]
                if i - 2 >= 0:
                    if keys[i - 2] == keys[i - 1] - 1:
                        if i - 3 >= 0:
                            another += arr[i - 3]
                    else:
                        another += arr[i - 2]
                arr[i] = max(arr[i], another)
        return arr[n - 1]
    
