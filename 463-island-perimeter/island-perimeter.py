# -*- coding:utf-8 -*-


# You are given a map in form of a two-dimensional integer grid where 1 represents land and 0 represents water. Grid cells are connected horizontally/vertically (not diagonally). The grid is completely surrounded by water, and there is exactly one island (i.e., one or more connected land cells). The island doesn't have "lakes" (water inside that isn't connected to the water around the island). One cell is a square with side length 1. The grid is rectangular, width and height don't exceed 100. Determine the perimeter of the island.
#
# Example:
#
# [[0,1,0,0],
#  [1,1,1,0],
#  [0,1,0,0],
#  [1,1,0,0]]
#
# Answer: 16
# Explanation: The perimeter is the 16 yellow stripes in the image below:
#
#
#


class Solution(object):
    def islandPerimeter(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        height = len(grid)
        if height == 0: 
            return 0
        width = len(grid[0])
        res = 0
        directions = [[1, 0], [-1, 0], [0, 1], [0, -1]]
        for y in range(height):
            for x in range(width):
                if grid[y][x] == 0:
                    continue
                for dir in directions:
                    nx = dir[0] + x
                    ny = dir[1] + y
                    if nx < 0 or nx >= width:
                        res += 1
                    elif ny < 0 or ny >= height:
                        res += 1
                    elif grid[ny][nx] == 0:
                        res += 1
        return res
        
