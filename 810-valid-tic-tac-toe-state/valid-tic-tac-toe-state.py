# -*- coding:utf-8 -*-


# A Tic-Tac-Toe board is given as a string array board. Return True if and only if it is possible to reach this board position during the course of a valid tic-tac-toe game.
#
# The board is a 3 x 3 array, and consists of characters " ", "X", and "O".  The " " character represents an empty square.
#
# Here are the rules of Tic-Tac-Toe:
#
#
# 	Players take turns placing characters into empty squares (" ").
# 	The first player always places "X" characters, while the second player always places "O" characters.
# 	"X" and "O" characters are always placed into empty squares, never filled ones.
# 	The game ends when there are 3 of the same (non-empty) character filling any row, column, or diagonal.
# 	The game also ends if all squares are non-empty.
# 	No more moves can be played if the game is over.
#
#
#
# Example 1:
# Input: board = ["O  ", "   ", "   "]
# Output: false
# Explanation: The first player always plays "X".
#
# Example 2:
# Input: board = ["XOX", " X ", "   "]
# Output: false
# Explanation: Players take turns making moves.
#
# Example 3:
# Input: board = ["XXX", "   ", "OOO"]
# Output: false
#
# Example 4:
# Input: board = ["XOX", "O O", "XOX"]
# Output: true
#
#
# Note:
#
#
# 	board is a length-3 array of strings, where each string board[i] has length 3.
# 	Each board[i][j] is a character in the set {" ", "X", "O"}.
#


class Solution(object):
    def validTicTacToe(self, board):
        """
        :type board: List[str]
        :rtype: bool
        """
        xnum, onum=0,0
        for i in range(3):
            for j in range(3):
                if board[i][j] == 'X':
                    xnum+=1
                if board[i][j] == 'O':
                    onum+=1
        if not (xnum-onum==1 or xnum==onum):
            return False
        
        x_r, o_r = 0, 0
        
        for i in range(3):
            if board[i][0] != ' ' and board[i][0] == board[i][1] and board[i][0] == board[i][2]:
                if board[i][0] == 'X':
                    x_r += 1
                else:
                    o_r += 1
            if board[0][i] != ' ' and board[0][i] == board[1][i] and board[0][i] == board[2][i]:
                if board[0][i] == 'X':
                    x_r += 1
                else:
                    o_r += 1
        
        if board[0][0] != ' ' and board[0][0] == board[1][1] and board[0][0] == board[2][2]:
            if board[0][0] == 'X':
                x_r += 1
            else:
                o_r += 1
        if board[0][2] != ' ' and board[0][2] == board[1][1] and board[0][2] == board[2][0]:
            if board[0][2] == 'X':
                x_r += 1
            else:
                o_r += 1
        
        if x_r+o_r > 1:
            return False
        if x_r+o_r == 0:
            return True
        if x_r == 1 and xnum==onum:
            return False
        if o_r == 1 and xnum-onum==1:
            return False
        return True
        
