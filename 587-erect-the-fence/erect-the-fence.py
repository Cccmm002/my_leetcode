# -*- coding:utf-8 -*-


# There are some trees, where each tree is represented by (x,y) coordinate in a two-dimensional garden. Your job is to fence the entire garden using the minimum length of rope as it is expensive. The garden is well fenced only if all the trees are enclosed. Your task is to help find the coordinates of trees which are exactly located on the fence perimeter.
#
# Example 1:
#
# Input: [[1,1],[2,2],[2,0],[2,4],[3,3],[4,2]]
# Output: [[1,1],[2,0],[4,2],[3,3],[2,4]]
# Explanation:
#
#
#
#
# Example 2:
#
# Input: [[1,2],[2,2],[4,2]]
# Output: [[1,2],[2,2],[4,2]]
# Explanation:
#
# Even you only have trees in a line, you need to use rope to enclose them. 
#
#
#
#  Note: 
#
# All trees should be enclosed together. You cannot cut the rope to enclose trees that will separate them in more than one group.
# All input integers will range from 0 to 100. 
# The garden has at least one tree. 
# All coordinates are distinct. 
# Input points have NO order. No order required for output.
#
#


# Definition for a point.
# class Point(object):
#     def __init__(self, a=0, b=0):
#         self.x = a
#         self.y = b

class Solution(object):
    def compare(self, a, b):
        ax = float(a[0])
        ay = float(a[1])
        bx = float(b[0])
        by = float(b[1])
        if ax >= 0 and bx < 0:
            return -1
        if ax < 0 and bx >= 0:
            return 1
        s_a = ay/ax if ax != 0 else float('inf')
        s_b = by/bx if bx != 0 else float('inf')
        if (s_a < s_b):
            return -1
        elif (s_a > s_b):
            return 1
        else:
            if ax != bx:
                return cmp(ax, bx)
            else:
                return cmp(ay,by)
            
    def outerTrees(self, points):
        """
        :type points: List[Point]
        :rtype: List[Point]
        """
        lp = len(points)
        if lp <= 2:
            return points
        lowest = points[0]
        for p in points:
            if p.y < lowest.y:
                lowest = p
        mpl = []
        for p in points:
            if p != lowest:
                mpl.append((p.x - lowest.x, p.y - lowest.y, p))
        mpl = sorted(mpl, lambda x, y: self.compare(x, y))
        
        i = len(mpl) - 1
        while i >= 0 and mpl[i][0] == 0:
            i -= 1
        l = i + 1
        h = len(mpl) - 1
        while l < h:
            tmp = mpl[l]
            mpl[l] = mpl[h]
            mpl[h] = tmp
            l += 1
            h -= 1
        
        stack = [(0, 0, lowest), mpl[0]]
        for i in range(1, len(mpl)):
            cp = -1
            while cp < 0:
                sl = len(stack)
                v1 = (stack[sl - 1][0] - stack[sl - 2][0], stack[sl - 1][1] - stack[sl - 2][1])
                v2 = (mpl[i][0] - stack[sl - 1][0], mpl[i][1] - stack[sl - 1][1])
                cp = v1[0]*v2[1] - v2[0]*v1[1]
                if (cp >= 0):
                    stack.append(mpl[i])
                else:
                    stack.pop()
        res = []
        for i in range(len(stack)):
            res.append(stack[i][2])
        return res
            
