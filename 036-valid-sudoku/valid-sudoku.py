# -*- coding:utf-8 -*-


# Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
#
# The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
#
#
#
# A partially filled sudoku which is valid.
#
#
# Note:
# A valid Sudoku board (partially filled) is not necessarily solvable. Only the filled cells need to be validated.


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
