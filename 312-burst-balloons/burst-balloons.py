# -*- coding:utf-8 -*-


# Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums. You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins. Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
#
# Find the maximum coins you can collect by bursting the balloons wisely.
#
# Note:
#
#
# 	You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
# 	0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
#
#
# Example:
#
#
# Input: [3,1,5,8]
# Output: 167 
# Explanation: nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
#              coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167
#
#


class Solution(object):
    def maxCoins(self, nums):
        """
        :type nums: List[int]
        :rtype: int
        """
        n = len(nums)
        nums.append(1)
        d = dict()
        
        def f(i,j):
            if i>j:
                return 0
            if (i, j) in d:
                return d[(i, j)]
            if i==j:
                return nums[i-1]*nums[i]*nums[i+1]
            res = 0
            for k in range(i,j + 1):
                res = max(res, f(i, k-1)+f(k+1, j) + nums[k]*nums[i-1]*nums[j+1])
            d[(i, j)] = res
            return res
        
        res = f(0, n-1)
        print(d)
        return res
