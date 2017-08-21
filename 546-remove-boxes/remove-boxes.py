# -*- coding:utf-8 -*-


# Given several boxes with different colors represented by different positive numbers. 
# You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (composed of k boxes, k >= 1), remove them and get k*k points.
# Find the maximum points you can get.
#
#
# Example 1:
# Input: 
#
# [1, 3, 2, 2, 2, 3, 4, 3, 1]
#
# Output:
#
# 23
#
# Explanation: 
#
# [1, 3, 2, 2, 2, 3, 4, 3, 1] 
# ----> [1, 3, 3, 4, 3, 1] (3*3=9 points) 
# ----> [1, 3, 3, 3, 1] (1*1=1 points) 
# ----> [1, 1] (3*3=9 points) 
# ----> [] (2*2=4 points)
#
#
#
# Note:
# The number of boxes n would not exceed 100.


class Solution(object):
    def removeBoxes(self, boxes):
        """
        :type boxes: List[int]
        :rtype: int
        """
        n = len(boxes)
        d = dict()
        
        def calc(i, j ,k):
            if i > j: return 0
            if i == j: return (k+1)*(k+1)
            t = (i, j, k)
            if t in d:
                return d[t]
            while i < j and boxes[i + 1] == boxes[i]:
                i += 1
                k += 1
            res = (k+1)*(k+1) + calc(i + 1, j, 0)
            for m in range(i + 1, j + 1):
                if boxes[i] != boxes[m]: continue
                cur = calc(i + 1, m - 1, 0) + calc(m, j, k + 1)
                res = max(res, cur)
            d[t] = res
            return res
        
        return calc(0, n - 1, 0)
    
