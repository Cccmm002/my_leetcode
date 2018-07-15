# -*- coding:utf-8 -*-


# Determine if a 9x9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:
#
#
# 	Each row must contain the digits 1-9 without repetition.
# 	Each column must contain the digits 1-9 without repetition.
# 	Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.
#
#
#
# A partially filled sudoku which is valid.
#
# The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
#
# Example 1:
#
#
# Input:
# [
#   ["5","3",".",".","7",".",".",".","."],
#   ["6",".",".","1","9","5",".",".","."],
#   [".","9","8",".",".",".",".","6","."],
#   ["8",".",".",".","6",".",".",".","3"],
#   ["4",".",".","8",".","3",".",".","1"],
#   ["7",".",".",".","2",".",".",".","6"],
#   [".","6",".",".",".",".","2","8","."],
#   [".",".",".","4","1","9",".",".","5"],
#   [".",".",".",".","8",".",".","7","9"]
# ]
# Output: true
#
#
# Example 2:
#
#
# Input:
# [
#   ["8","3",".",".","7",".",".",".","."],
#   ["6",".",".","1","9","5",".",".","."],
#   [".","9","8",".",".",".",".","6","."],
#   ["8",".",".",".","6",".",".",".","3"],
#   ["4",".",".","8",".","3",".",".","1"],
#   ["7",".",".",".","2",".",".",".","6"],
#   [".","6",".",".",".",".","2","8","."],
#   [".",".",".","4","1","9",".",".","5"],
#   [".",".",".",".","8",".",".","7","9"]
# ]
# Output: false
# Explanation: Same as Example 1, except with the 5 in the top left corner being 
#     modified to 8. Since there are two 8's in the top left 3x3 sub-box, it is invalid.
#
#
# Note:
#
#
# 	A Sudoku board (partially filled) could be valid but is not necessarily solvable.
# 	Only the filled cells need to be validated according to the mentioned rules.
# 	The given board contain only digits 1-9 and the character '.'.
# 	The given board size is always 9x9.
#
#


class Solution(object):
    def isValidSudoku(self, board):
        """
        :type board: List[List[str]]
        :rtype: bool
        """
        for line in board:
            s = set()
            for c in line:
                if c == '.':
                    continue
                n = int(c)
                if n in s:
                    return False
                else:
                    s.add(n)
        for i in range(0, len(board[0])):
            s = set()
            for j in range(0, len(board)):
                c = board[j][i]
                if c == '.':
                    continue
                n = int(c)
                if n in s:
                    return False
                else:
                    s.add(n)
        sp = [[0, 0], [3, 0], [6, 0], [0, 3], [3, 3], [6, 3], [0, 6], [3, 6], [6, 6]]
        np = [[0, 0], [1, 0], [2, 0], [0, 1], [1, 1], [2, 1], [0, 2], [1, 2], [2, 2]]
        for i in range(0, len(sp)):
            s = set()
            for j in range(0, len(np)):
                x = sp[i][0] + np[j][0]
                y = sp[i][1] + np[j][1]
                c = board[x][y]
                if c == '.':
                    continue
                n = int(c)
                if n in s:
                    return False
                else:
                    s.add(n)
        return True
