# -*- coding:utf-8 -*-


# Given an integer matrix, find the length of the longest increasing path.
#
#
# From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
#
#
# Example 1:
#
# nums = [
#   [9,9,4],
#   [6,6,8],
#   [2,1,1]
# ]
#
#
#
#
# Return 4
#
# The longest increasing path is [1, 2, 6, 9].
#
#
# Example 2:
#
# nums = [
#   [3,4,5],
#   [3,2,6],
#   [2,2,1]
# ]
#
#
#
#
# Return 4
#
# The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
#
# Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution(object):
    def longestIncreasingPath(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: int
        """
        height = len(matrix)
        if height == 0:
            return 0
        width = len(matrix[0])
        if width == 0:
            return 0
        d = dict()
        
        def calc(x, y):
            t = (x, y)
            if t in d:
                return d[t]
            res = 0
            directions = [[0, 1], [0, -1], [1, 0], [-1, 0]]
            for dir in directions:
                nx = x + dir[0]
                ny = y + dir[1]
                if nx < 0 or ny < 0 or nx >= width or ny >= height:
                    continue
                if matrix[ny][nx] > matrix[y][x]:
                    res = max(res, calc(nx, ny))
            d[t] = res + 1
            return res + 1
        
        maxx = 0
        for i in range(height):
            for j in range(width):
                maxx = max(maxx, calc(j, i))
        return maxx
        
