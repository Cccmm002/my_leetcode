# -*- coding:utf-8 -*-


# Given a collection of intervals, merge all overlapping intervals.
#
# Example 1:
#
#
# Input: [[1,3],[2,6],[8,10],[15,18]]
# Output: [[1,6],[8,10],[15,18]]
# Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
#
#
# Example 2:
#
#
# Input: [[1,4],[4,5]]
# Output: [[1,5]]
# Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
#


# Definition for an interval.
# class Interval(object):
#     def __init__(self, s=0, e=0):
#         self.start = s
#         self.end = e

class Solution(object):
    def merge(self, intervals):
        """
        :type intervals: List[Interval]
        :rtype: List[Interval]
        """
        intervals = sorted(intervals, cmp=lambda x,y: cmp(x.start, y.start))
        if len(intervals) <= 0:
            return []
        res = []
        cur = intervals[0]
        for i in range(1, len(intervals)):
            if intervals[i].start <= cur.end:
                cur.end = max(intervals[i].end, cur.end)
            else:
                res.append(cur)
                cur = intervals[i]
        res.append(cur)
        return res
