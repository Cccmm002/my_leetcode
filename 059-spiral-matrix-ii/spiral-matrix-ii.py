# -*- coding:utf-8 -*-


# Given a positive integer n, generate a square matrix filled with elements from 1 to n2 in spiral order.
#
# Example:
#
#
# Input: 3
# Output:
# [
#  [ 1, 2, 3 ],
#  [ 8, 9, 4 ],
#  [ 7, 6, 5 ]
# ]
#
#


class Solution(object):
    def generateMatrix(self, n):
        """
        :type n: int
        :rtype: List[List[int]]
        """
        if n == 0: return []
        if n == 1: return [[1]]
        m = [[0 for j in range(n)] for i in range(n)]  # m[y][x]
        next_dir = {0: 1, 1:2, 2:3, 3:0}  # 0: right; 1: down; 2: left; 3: up
        d = {0: (0, 1), 1: (1, 0), 2: (0, -1), 3: (-1, 0)}  # (y, x)
        curx = 0
        cury = 0
        curdir = 0
        for i in range(1, n*n + 1):
            m[cury][curx] = i
            attempt_x = curx + d[curdir][1]
            attempt_y = cury + d[curdir][0]
            if attempt_x >= n or attempt_y >= n or attempt_x < 0 or attempt_y < 0 or m[attempt_y][attempt_x] != 0:
                curdir = next_dir[curdir]
            curx = curx + d[curdir][1]
            cury = cury + d[curdir][0]
        return m
        
