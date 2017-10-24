# -*- coding:utf-8 -*-


# Given a n x n matrix where each of the rows and columns are sorted in ascending order, find the kth smallest element in the matrix.
#
#
# Note that it is the kth smallest element in the sorted order, not the kth distinct element.
#
#
# Example:
#
# matrix = [
#    [ 1,  5,  9],
#    [10, 11, 13],
#    [12, 13, 15]
# ],
# k = 8,
#
# return 13.
#
#
#
# Note: 
# You may assume k is always valid, 1 &le; k &le; n2.


class Solution(object):
    def kthSmallest(self, matrix, k):
        """
        :type matrix: List[List[int]]
        :type k: int
        :rtype: int
        """
        import heapq
        height = len(matrix)
        width = len(matrix[0])
        heap = []
        for i in range(width):
            heapq.heappush(heap, (matrix[0][i], 0, i))
        for i in range(k - 1):
            cur = heapq.heappop(heap)
            if cur[1] + 1 >= height:
                continue
            heapq.heappush(heap, (matrix[cur[1] + 1][cur[2]], cur[1] + 1, cur[2]))
        r = heapq.heappop(heap)
        return r[0]
    
