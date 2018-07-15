# -*- coding:utf-8 -*-


# Given a picture consisting of black and white pixels, and a positive integer N, find the number of black pixels located at some specific row R and column C that align with all the following rules:
#
#
#  Row R and column C both contain exactly N black pixels.
#  For all rows that have a black pixel at column C, they should be exactly the same as row R
#
#
# The picture is represented by a 2D char array consisting of 'B' and 'W', which means black and white pixels respectively. 
#
# Example:
#
# Input:                                            
# [['W', 'B', 'W', 'B', 'B', 'W'],    
#  ['W', 'B', 'W', 'B', 'B', 'W'],    
#  ['W', 'B', 'W', 'B', 'B', 'W'],    
#  ['W', 'W', 'B', 'W', 'B', 'W']] 
#
# N = 3
# Output: 6
# Explanation: All the bold 'B' are the black pixels we need (all 'B's at column 1 and 3).
#         0    1    2    3    4    5         column index                                            
# 0    [['W', 'B', 'W', 'B', 'B', 'W'],    
# 1     ['W', 'B', 'W', 'B', 'B', 'W'],    
# 2     ['W', 'B', 'W', 'B', 'B', 'W'],    
# 3     ['W', 'W', 'B', 'W', 'B', 'W']]    
# row index
#
# Take 'B' at row R = 0 and column C = 1 as an example:
# Rule 1, row R = 0 and column C = 1 both have exactly N = 3 black pixels. 
# Rule 2, the rows have black pixel at column C = 1 are row 0, row 1 and row 2. They are exactly the same as row R = 0.
#
#
#
#
# Note:
#
# The range of width and height of the input 2D array is [1,200].
#
#


class Solution(object):
    def findBlackPixel(self, picture, N):
        """
        :type picture: List[List[str]]
        :type N: int
        :rtype: int
        """
        height = len(picture)
        if height == 0: return 0
        width = len(picture[0])
        row = [set() for i in range(height)]
        col = [set() for i in range(width)]
        for i in range(height):
            for j in range(width):
                if picture[i][j] == 'B':
                    row[i].add(j)
        for i in range(width):
            for j in range(height):
                if picture[j][i] == 'B':
                    col[i].add(j)
        res = 0
        for i in range(height):
            if len(row[i]) != N: continue
            for c in row[i]:
                if len(col[c]) == N:
                    l = list(col[c])[0]
                    flag = True
                    for r in col[c]:
                        if row[l] != row[r]:
                            flag = False
                            break
                    if flag:
                        res += 1
        return res
    
