# -*- coding:utf-8 -*-


# Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
#
# Note:
#
# The solution set must not contain duplicate quadruplets.
#
# Example:
#
#
# Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
#
# A solution set is:
# [
#   [-1,  0, 0, 1],
#   [-2, -1, 1, 2],
#   [-2,  0, 0, 2]
# ]
#
#


class Solution(object):
    def fourSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[List[int]]
        """
        m = dict()
        res = set()
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i == j:
                    continue
                s = nums[i] + nums[j]
                if s in m:
                    m[s].add(frozenset([i, j]))
                else:
                    m[s] = set([frozenset([i, j])])
        for i in range(len(nums)):
            for j in range(len(nums)):
                if i == j:
                    continue
                s = nums[i] + nums[j]
                t = target - s
                if t not in m:
                    continue
                for r in m[t]:
                    if i in r or j in r:
                        continue
                    l = list(r)
                    l.append(i)
                    l.append(j)
                    res.add(frozenset(l))
        ress = set()
        print(res)
        for s in res:
            l = list(s)
            rl = [nums[l[0]], nums[l[1]], nums[l[2]], nums[l[3]]]
            rl.sort()
            ress.add(tuple(rl))
        return list(ress)
        
