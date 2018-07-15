# -*- coding:utf-8 -*-


#
# Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
#
# Example:
# Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
#
#
# The input is:  vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector<double>.
#
#
# According to the example above:
# equations = [ ["a", "b"], ["b", "c"] ],
# values = [2.0, 3.0],
# queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
#
#
#
# The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.
#


from collections import deque

class Solution(object):
    def bfs(self, query, graph):
        source, target = query
        q = deque()
        q.append((source, 1))
        visited = set()
        visited.add(source)
        while len(q) > 0:
            cur, val = q.popleft()
            if cur not in graph:
                return -1
            for node in graph[cur]:
                v = graph[cur][node]
                if node == target:
                    return val*v
                if node in visited:
                    continue
                q.append((node, val*v))
                visited.add(node)
        return -1.0
        
    def calcEquation(self, equations, values, queries):
        """
        :type equations: List[List[str]]
        :type values: List[float]
        :type queries: List[List[str]]
        :rtype: List[float]
        """
        graph = dict()
        n = len(equations)
        for i in range(n):
            a, b = equations[i]
            v = values[i]
            if a not in graph:
                graph[a] = dict()
            if b not in graph:
                graph[b] = dict()
            graph[a][b] = v
            graph[b][a] = 1.0/v
            
        res = []
        for query in queries:
            res.append(self.bfs(query, graph))
        return res
