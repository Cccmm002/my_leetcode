# -*- coding:utf-8 -*-


# Given a picture consisting of black and white pixels, find the number of black lonely pixels.
#
# The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively. 
#
# A black lonely pixel is character 'B' that located at a specific position where the same row and same column don't have any other black pixels.
#
# Example:
#
# Input: 
# [['W', 'W', 'B'],
#  ['W', 'B', 'W'],
#  ['B', 'W', 'W']]
#
# Output: 3
# Explanation: All the three 'B's are black lonely pixels.
#
#
#
# Note:
#
# The range of width and height of the input 2D array is [1,500].
#
#


class Solution(object):
    def findLonelyPixel(self, picture):
        """
        :type picture: List[List[str]]
        :rtype: int
        """
        height = len(picture)
        if height == 0: return 0
        width = len(picture[0])
        row = [-1 for i in range(height)]
        col = [-1 for i in range(width)]
        for i in range(height):
            count = 0
            loc = -1
            for j in range(width):
                if picture[i][j] == 'B':
                    count += 1
                    loc = j
            if count == 1:
                row[i] = loc
        for i in range(width):
            count = 0
            loc = -1
            for j in range(height):
                if picture[j][i] == 'B':
                    count += 1
                    loc = j
            if count == 1:
                col[i] = loc
        res = 0
        for i in range(height):
            if row[i] < 0: continue
            if col[row[i]] == i: res += 1
        return res
    
