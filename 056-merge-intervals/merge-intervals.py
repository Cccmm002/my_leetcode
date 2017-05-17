# -*- coding:utf-8 -*-


# Given a collection of intervals, merge all overlapping intervals.
#
#
# For example,
# Given [1,3],[2,6],[8,10],[15,18],
# return [1,6],[8,10],[15,18].


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
