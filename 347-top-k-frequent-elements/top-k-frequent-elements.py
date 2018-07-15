# -*- coding:utf-8 -*-


#
# Given a non-empty array of integers, return the k most frequent elements.
#
# For example,
# Given [1,1,1,2,2,3] and k = 2, return [1,2].
#
#
# Note: 
#
# You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
# Your algorithm's time complexity must be better than O(n log n), where n is the array's size.
#


class Solution(object):
    def topKFrequent(self, nums, k):
        """
        :type nums: List[int]
        :type k: int
        :rtype: List[int]
        """
        import heapq
        d = dict()
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        heap = []
        for key in d:
            t = (d[key], key)
            if len(heap) < k:
                heapq.heappush(heap, t)
            else:
                if d[key] > heap[0][0]:
                    heapq.heappop(heap)
                    heapq.heappush(heap, t)
        res = []
        while len(heap) != 0:
            res.append(heapq.heappop(heap)[1])
        return res
        
