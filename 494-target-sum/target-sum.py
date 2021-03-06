# -*- coding:utf-8 -*-


#
# You are given a list of non-negative integers, a1, a2, ..., an, and a target, S. Now you have 2 symbols + and -. For each integer, you should choose one from + and - as its new symbol.
#
#
# Find out how many ways to assign symbols to make sum of integers equal to target S.  
#
#
# Example 1:
#
# Input: nums is [1, 1, 1, 1, 1], S is 3. 
# Output: 5
# Explanation: 
#
# -1+1+1+1+1 = 3
# +1-1+1+1+1 = 3
# +1+1-1+1+1 = 3
# +1+1+1-1+1 = 3
# +1+1+1+1-1 = 3
#
# There are 5 ways to assign symbols to make the sum of nums be target 3.
#
#
#
# Note:
#
# The length of the given array is positive and will not exceed 20. 
# The sum of elements in the given array will not exceed 1000.
# Your output answer is guaranteed to be fitted in a 32-bit integer.
#
#


class Solution(object):
    def findTargetSumWays(self, nums, S):
        """
        :type nums: List[int]
        :type S: int
        :rtype: int
        """
        n = len(nums)
        d = dict()
        
        def solve(x, n):
            if x == 0:
                if n == 0 and nums[0] == 0:
                    return 2;
                elif nums[0] == n or nums[0] == 0 - n:
                    return 1;
                else:
                    return 0;
            t = (x, n)
            if t in d:
                return d[t]
            res = solve(x - 1, n + nums[x]) + solve(x - 1, n - nums[x])
            d[t] = res
            return res
        
        r = solve(n - 1, S)
        for k in d:
            if d[k] != 0:
                print(str(k) + str(d[k]))
        return r
        
