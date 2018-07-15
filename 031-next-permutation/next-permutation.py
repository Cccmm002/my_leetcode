# -*- coding:utf-8 -*-


# Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
#
# If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
#
# The replacement must be in-place and use only constant extra memory.
#
# Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
#
# 1,2,3 → 1,3,2
# 3,2,1 → 1,2,3
# 1,1,5 → 1,5,1
#


class Solution(object):
    def nextPermutation(self, nums):
        """
        :type nums: List[int]
        :rtype: void Do not return anything, modify nums in-place instead.
        """
        current = nums
        n = len(current)
        p = n - 2
        while p >= 0 and current[p] >= current[p + 1]:
            p -= 1
        if p < 0:
            return nums.sort()
        small, index = current[p + 1], p + 1
        for i in range(p + 2, n):
            if current[i] > current[p] and current[i] < small:
                small = current[i]
                index = i
        res = current[:]
        res[index] = current[p]
        res[p] = small
        rr = res[:p + 1] + sorted(res[p + 1:])
        nums[:] = rr
        
