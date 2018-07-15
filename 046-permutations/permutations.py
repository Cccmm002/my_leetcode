# -*- coding:utf-8 -*-


# Given a collection of distinct integers, return all possible permutations.
#
# Example:
#
#
# Input: [1,2,3]
# Output:
# [
#   [1,2,3],
#   [1,3,2],
#   [2,1,3],
#   [2,3,1],
#   [3,1,2],
#   [3,2,1]
# ]
#
#


class Solution(object):
    def generate(self, nums, got):
        if all(got):
            return []
        n = len(nums)
        res = []
        for i in range(n):
            if got[i]:
                continue
            ng = got[:]
            ng[i] = True
            nxt = self.generate(nums, ng)
            if len(nxt) > 0:
                for p in nxt:
                    res.append([nums[i]] + p)
            else:
                res.append([nums[i]])
        return res
        
    def permute(self, nums):
        """
        :type nums: List[int]
        :rtype: List[List[int]]
        """
        n = len(nums)
        if n == 0:
            return []
        got = [False for _ in range(n)]
        return self.generate(nums, got)
    
