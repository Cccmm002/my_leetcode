# -*- coding:utf-8 -*-


# Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
#
#
#
# For example,
# Given the following matrix:
#
#
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
#
#
# You should return [1,2,3,6,9,8,7,4,5].


class Solution(object):
    def spiralOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        m = len(matrix)
        if m == 0: return []
        n = len(matrix[0])
        res = [0 for i in range(n*m)]
        next_dir = {0: 1, 1:2, 2:3, 3:0}  # 0: right; 1: down; 2: left; 3: up
        d = {0: (0, 1), 1: (1, 0), 2: (0, -1), 3: (-1, 0)}  # (y, x)
        curx = 0
        cury = 0
        curdir = 0
        for i in range(1, m*n + 1):
            res[i - 1] = matrix[cury][curx]
            matrix[cury][curx] = 0
            attempt_x = curx + d[curdir][1]
            attempt_y = cury + d[curdir][0]
            if attempt_x >= n or attempt_y >= m or attempt_x < 0 or attempt_y < 0 or matrix[attempt_y][attempt_x] == 0:
                curdir = next_dir[curdir]
            curx = curx + d[curdir][1]
            cury = cury + d[curdir][0]
        return res
        
