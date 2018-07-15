# -*- coding:utf-8 -*-


# On a 2x3 board, there are 5 tiles represented by the integers 1 through 5, and an empty square represented by 0.
#
# A move consists of choosing 0 and a 4-directionally adjacent number and swapping it.
#
# The state of the board is solved if and only if the board is [[1,2,3],[4,5,0]].
#
# Given a puzzle board, return the least number of moves required so that the state of the board is solved. If it is impossible for the state of the board to be solved, return -1.
#
# Examples:
#
#
# Input: board = [[1,2,3],[4,0,5]]
# Output: 1
# Explanation: Swap the 0 and the 5 in one move.
#
#
#
# Input: board = [[1,2,3],[5,4,0]]
# Output: -1
# Explanation: No number of moves will make the board solved.
#
#
#
# Input: board = [[4,1,2],[5,0,3]]
# Output: 5
# Explanation: 5 is the smallest number of moves that solves the board.
# An example path:
# After move 0: [[4,1,2],[5,0,3]]
# After move 1: [[4,1,2],[0,5,3]]
# After move 2: [[0,1,2],[4,5,3]]
# After move 3: [[1,0,2],[4,5,3]]
# After move 4: [[1,2,0],[4,5,3]]
# After move 5: [[1,2,3],[4,5,0]]
#
#
#
# Input: board = [[3,2,4],[1,5,0]]
# Output: 14
#
#
# Note:
#
#
# 	board will be a 2 x 3 array as described above.
# 	board[i][j] will be a permutation of [0, 1, 2, 3, 4, 5].
#


import copy
import collections

class Board(object):
    def __init__(self, l):
        self.b = (tuple(l[0]), tuple(l[1]))
    
    def __eq__(self, other):
        return self.b[0] == other.b[0] and self.b[1] == other.b[1]
    
    def __ne__(self, other):
        return not self.__eq__(other)
    
    def __hash__(self):
        return hash(self.b[0]) + hash(self.b[1])
    
    def moves(self):
        x, y = 0, 0
        for i in range(2):
            for j in range(3):
                if self.b[i][j] == 0:
                    x, y = j, i
                    break
        res = []
        l = [list(self.b[0]), list(self.b[1])]
        if x > 0:
            nl = copy.deepcopy(l)
            nl[y][x] = nl[y][x - 1]
            nl[y][x - 1] = 0
            res.append(Board(nl))
        if x < 2:
            nl = copy.deepcopy(l)
            nl[y][x] = nl[y][x + 1]
            nl[y][x + 1] = 0
            res.append(Board(nl))
        if y > 0:
            nl = copy.deepcopy(l)
            nl[y][x] = nl[y - 1][x]
            nl[y - 1][x] = 0
            res.append(Board(nl))
        if y < 1:
            nl = copy.deepcopy(l)
            nl[y][x] = nl[y + 1][x]
            nl[y + 1][x] = 0
            res.append(Board(nl))
        return res

class Solution(object):
    def slidingPuzzle(self, board):
        """
        :type board: List[List[int]]
        :rtype: int
        """
        root = Board(board)
        solved = Board([[1,2,3],[4,5,0]])
        if root == solved:
            return 0
        visited = set()
        q = collections.deque()
        q.append((root, 0))
        visited.add(root)
        while len(q) > 0:
            cur = q.popleft()
            nxt = cur[0].moves()
            for n in nxt:
                if n in visited:
                    continue
                if n == solved:
                    return cur[1] + 1
                visited.add(n)
                q.append((n, cur[1] + 1))
        return -1
