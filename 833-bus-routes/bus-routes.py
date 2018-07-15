# -*- coding:utf-8 -*-


# We have a list of bus routes. Each routes[i] is a bus route that the i-th bus repeats forever. For example if routes[0] = [1, 5, 7], this means that the first bus (0-th indexed) travels in the sequence 1->5->7->1->5->7->1->... forever.
#
# We start at bus stop S (initially not on a bus), and we want to go to bus stop T. Travelling by buses only, what is the least number of buses we must take to reach our destination? Return -1 if it is not possible.
#
#
# Example:
# Input: 
# routes = [[1, 2, 7], [3, 6, 7]]
# S = 1
# T = 6
# Output: 2
# Explanation: 
# The best strategy is take the first bus to the bus stop 7, then take the second bus to the bus stop 6.
#
#
# Note: 
#
#
# 	1 <= routes.length <= 500.
# 	1 <= routes[i].length <= 500.
# 	0 <= routes[i][j] < 10 ^ 6.
#


import itertools
import collections

class Solution(object):
    def numBusesToDestination(self, routes, S, T):
        """
        :type routes: List[List[int]]
        :type S: int
        :type T: int
        :rtype: int
        """
        if S == T: return 0
        sr = dict()
        for r in range(len(routes)):
            for station in routes[r]:
                if station not in sr:
                    sr[station] = set()
                sr[station].add(r)
        graph = dict()
        for station in sr:
            if len(sr[station]) <= 1: continue
            for p in itertools.permutations(sr[station], 2):
                a, b = p[0], p[1]
                if a not in graph:
                    graph[a] = set()
                graph[a].add(b)
        final_res = None
        for start in sr[S]:
            visited = set()
            q = collections.deque()
            q.append((start, 0))
            while len(q) > 0:
                _cur = q.popleft()
                cur, level = _cur[0], _cur[1]
                if cur in sr[T]:
                    if final_res is None:
                        final_res = level
                    else:
                        final_res = min(final_res, level)
                    break
                visited.add(cur)
                if cur not in graph: continue
                for nxt in graph[cur]:
                    if nxt in visited: continue
                    q.append((nxt, level + 1))
        if final_res is None:
            return -1
        else:
            return final_res + 1
        
