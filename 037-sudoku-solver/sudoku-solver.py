# -*- coding:utf-8 -*-


# Write a program to solve a Sudoku puzzle by filling the empty cells.
#
# A sudoku solution must satisfy all of the following rules:
#
#
# 	Each of the digits 1-9 must occur exactly once in each row.
# 	Each of the digits 1-9 must occur exactly once in each column.
# 	Each of the the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
#
#
# Empty cells are indicated by the character '.'.
#
#
# A sudoku puzzle...
#
#
# ...and its solution numbers marked in red.
#
# Note:
#
#
# 	The given board contain only digits 1-9 and the character '.'.
# 	You may assume that the given Sudoku puzzle will have a single unique solution.
# 	The given board size is always 9x9.
#
#


class Solution(object):
    def solveSudoku(self, board):
        for i in range(9):
            board[i] = list(board[i])
        sp = [[0, 0], [3, 0], [6, 0], [0, 3], [3, 3], [6, 3], [0, 6], [3, 6], [6, 6]]
        np = [[0, 0], [1, 0], [2, 0], [0, 1], [1, 1], [2, 1], [0, 2], [1, 2], [2, 2]]
        dict_template = {1: 0, 2: 0, 3: 0, 4: 0, 5: 0, 6: 0, 7: 0, 8: 0, 9: 0}
        todoList = []
        hashList = [[dict_template.copy() if board[i][j] == '.' else None for j in range(9)] for i in range(9)]
    
        def add_constraint(i, j, cur):
            for k in range(9):
                if hashList[i][k] is not None:
                    hashList[i][k][cur] += 1
                if hashList[k][j] is not None:
                    hashList[k][j][cur] += 1
            sx = i / 3
            sy = j / 3
            for k in range(9):
                x = sx * 3 + np[k][0]
                y = sy * 3 + np[k][1]
                if hashList[x][y] is not None:
                    hashList[x][y][cur] += 1
    
        def remove_constraint(i, j, cur):
            for k in range(9):
                if hashList[i][k] is not None:
                    hashList[i][k][cur] -= 1
                if hashList[k][j] is not None:
                    hashList[k][j][cur] -= 1
            sx = i / 3
            sy = j / 3
            for k in range(9):
                x = sx * 3 + np[k][0]
                y = sy * 3 + np[k][1]
                if hashList[x][y] is not None:
                    hashList[x][y][cur] -= 1
    
        for i in range(9):
            for j in range(9):
                if board[i][j] == '.':
                    todoList.append((i, j))
                    continue
                cur = int(board[i][j])
                add_constraint(i, j, cur)
    
        todo_count = len(todoList)
    
        def solver(index):
            if index == todo_count:
                return True
            (i, j) = todoList[index]
            for n in range(1, 10):
                if hashList[i][j][n] > 0:
                    continue
                add_constraint(i, j, n)
                board[i][j] = str(n)
                next = solver(index + 1)
                if next:
                    return True
                else:
                    remove_constraint(i, j, n)
            board[i][j] = '.'
            return False
    
        solver(0)
        for i in range(9):
            board[i] = ''.join(board[i])
        
