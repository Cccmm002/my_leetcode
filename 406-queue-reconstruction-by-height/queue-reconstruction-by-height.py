# -*- coding:utf-8 -*-


# Suppose you have a random list of people standing in a queue. Each person is described by a pair of integers (h, k), where h is the height of the person and k is the number of people in front of this person who have a height greater than or equal to h. Write an algorithm to reconstruct the queue.
#
#
# Note:
# The number of people is less than 1,100.
#
#
#
#
# Example
#
# Input:
# [[7,0], [4,4], [7,1], [5,0], [6,1], [5,2]]
#
# Output:
# [[5,0], [7,0], [5,2], [6,1], [4,4], [7,1]]
#
#


class Solution(object):
    def reconstructQueue(self, people):
        """
        :type people: List[List[int]]
        :rtype: List[List[int]]
        """
        d = dict()
        for p in people:
            if p[0] in d:
                d[p[0]].append(p[1])
            else:
                d[p[0]] = [p[1]]
        all_heights = list(d.keys())
        all_heights.sort(reverse=True)
        res = []
        for i in range(len(all_heights)):
            cur = sorted(d[all_heights[i]])
            for j in range(len(cur)):
                t = [all_heights[i], cur[j]]
                res.insert(t[1], t)
        return res
    
