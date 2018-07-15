# -*- coding:utf-8 -*-


#
# There are N network nodes, labelled 1 to N.
#
# Given times, a list of travel times as directed edges times[i] = (u, v, w), where u is the source node, v is the target node, and w is the time it takes for a signal to travel from source to target.
#
# Now, we send a signal from a certain node K.  How long will it take for all nodes to receive the signal?  If it is impossible, return -1.
#
#
# Note:
#
# N will be in the range [1, 100].
# K will be in the range [1, N].
# The length of times will be in the range [1, 6000].
# All edges times[i] = (u, v, w) will have 1 <= u, v <= N and 1 <= w <= 100.
#
#


import heapq

class Solution(object):
    def networkDelayTime(self, times, N, K):
        """
        :type times: List[List[int]]
        :type N: int
        :type K: int
        :rtype: int
        """
        ts = [[] for _ in range(N + 1)]
        for t in times:
            ts[t[0]].append((t[1], t[2]))
        
        h = []
        heapq.heappush(h, (0, K))
        reached = [False for _ in range(N + 1)]
        res = 0
        while len(h) > 0:
            top = heapq.heappop(h)
            if reached[top[1]]:
                continue
            reached[top[1]] = True
            res = max(res, top[0])
            for t in ts[top[1]]:
                nxt = t[0]
                if reached[nxt]:
                    continue
                heapq.heappush(h, (top[0] + t[1], nxt))
        for i in range(1, N + 1):
            if not reached[i]:
                return -1
        return res
    
