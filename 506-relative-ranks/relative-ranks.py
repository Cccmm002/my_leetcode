# -*- coding:utf-8 -*-


#
# Given scores of N athletes, find their relative ranks and the people with the top three highest scores, who will be awarded medals: "Gold Medal", "Silver Medal" and "Bronze Medal".
#
# Example 1:
#
# Input: [5, 4, 3, 2, 1]
# Output: ["Gold Medal", "Silver Medal", "Bronze Medal", "4", "5"]
# Explanation: The first three athletes got the top three highest scores, so they got "Gold Medal", "Silver Medal" and "Bronze Medal". For the left two athletes, you just need to output their relative ranks according to their scores.
#
#
#
# Note:
#
# N is a positive integer and won't exceed 10,000.
# All the scores of athletes are guaranteed to be unique.
#
#
#


class Solution(object):
    def findRelativeRanks(self, nums):
        """
        :type nums: List[int]
        :rtype: List[str]
        """
        tl = [(nums[i], i) for i in range(len(nums))]
        tl = sorted(tl, cmp=lambda x, y: 0 - cmp(x[0], y[0]))
        res = ['' for i in range(len(nums))]
        for i in range(len(tl)):
            if i == 0:
                res[tl[i][1]] = 'Gold Medal'
            elif i == 1:
                res[tl[i][1]] = 'Silver Medal'
            elif i == 2:
                res[tl[i][1]] = 'Bronze Medal'
            else:
                res[tl[i][1]] = str(i + 1)
        return res
        
