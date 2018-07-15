# -*- coding:utf-8 -*-


# This question is about implementing a basic elimination algorithm for Candy Crush.
#
# Given a 2D integer array board representing the grid of candy, different positive integers board[i][j] represent different types of candies.  A value of board[i][j] = 0 represents that the cell at position (i, j) is empty.  The given board represents the state of the game following the player's move.  Now, you need to restore the board to a stable state by crushing candies according to the following rules:
#
#
# If three or more candies of the same type are adjacent vertically or horizontally, "crush" them all at the same time - these positions become empty.
# After crushing all candies simultaneously, if an empty space on the board has candies on top of itself, then these candies will drop until they hit a candy or bottom at the same time. (No new candies will drop outside the top boundary.)
# After the above steps, there may exist more candies that can be crushed.  If so, you need to repeat the above steps.
# If there does not exist more candies that can be crushed (ie. the board is stable), then return the current board.
#
#
# You need to perform the above rules until the board becomes stable, then return the current board.
#
# Example 1:
#
# Input:
# board = 
# [[110,5,112,113,114],[210,211,5,213,214],[310,311,3,313,314],[410,411,412,5,414],[5,1,512,3,3],[610,4,1,613,614],[710,1,2,713,714],[810,1,2,1,1],[1,1,2,2,2],[4,1,4,4,1014]]
# Output:
# [[0,0,0,0,0],[0,0,0,0,0],[0,0,0,0,0],[110,0,0,0,114],[210,0,0,0,214],[310,0,0,113,314],[410,0,0,213,414],[610,211,112,313,614],[710,311,412,613,714],[810,411,512,713,1014]]
# Explanation: 
#
#
#
#
# Note:
#
# The length of board will be in the range [3, 50].
# The length of board[i] will be in the range [3, 50].
# Each board[i][j] will initially start as an integer in the range [1, 2000].
#
#


class Solution(object):
    def candyCrush(self, board):
        """
        :type board: List[List[int]]
        :rtype: List[List[int]]
        """
        negative = False
        height = len(board)
        width = len(board[0])
        for r in range(height):
            for c in range(width - 2):
                if abs(board[r][c]) == abs(board[r][c + 1]) and abs(board[r][c]) == abs(board[r][c + 2]) and abs(board[r][c]) != 0:
                    board[r][c] = -abs(board[r][c])
                    board[r][c + 1] = -abs(board[r][c + 1])
                    board[r][c + 2] = -abs(board[r][c + 2])
                    negative = True
        for c in range(width):
            for r in range(height - 2):
                if abs(board[r][c]) == abs(board[r + 1][c]) and abs(board[r + 1][c]) == abs(board[r + 2][c]) and abs(board[r][c]) != 0:
                    board[r][c] = -abs(board[r][c])
                    board[r + 1][c] = -abs(board[r + 1][c])
                    board[r + 2][c] = -abs(board[r + 2][c])
                    negative = True
        for c in range(width):
            prev = height - 1
            for r in range(height - 1, -1, -1):
                if board[r][c] > 0:
                    board[prev][c] = board[r][c]
                    prev -= 1
            while prev >= 0:
                board[prev][c] = 0
                prev -= 1
        if negative:
            return self.candyCrush(board[:])
        else:
            return board
    
