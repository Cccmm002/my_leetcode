# -*- coding:utf-8 -*-


#
# Given a matrix of M x N elements (M rows, N columns), return all elements of the matrix in diagonal order as shown in the below image. 
#
#
# Example:
#
# Input:
# [
#  [ 1, 2, 3 ],
#  [ 4, 5, 6 ],
#  [ 7, 8, 9 ]
# ]
# Output:  [1,2,4,7,5,3,6,8,9]
# Explanation:
#
#
#
#
# Note:
#
# The total number of elements of the given matrix will not exceed 10,000.
#
#


class Solution(object):
    def findDiagonalOrder(self, matrix):
        """
        :type matrix: List[List[int]]
        :rtype: List[int]
        """
        res = []
        m = len(matrix)
        if m == 0: 
            return res
        n = len(matrix[0])
        x = 0
        y = 0
        upper = True
        while True:
            res.append(matrix[y][x])
            if x == n - 1 and y == m - 1:
                break
            if upper:
                if x == n - 1:
                    y += 1
                    upper = False
                    continue
                if y == 0:
                    x += 1
                    upper = False
                    continue
            else:
                if y == m - 1:
                    x += 1
                    upper = True
                    continue
                if x == 0:
                    y += 1
                    upper = True
                    continue
            if upper:
                x += 1
                y -= 1
            else:
                x -= 1
                y += 1
        return res
        
