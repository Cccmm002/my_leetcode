# -*- coding:utf-8 -*-


# Given n points on a 2D plane, find if there is such a line parallel to y-axis that reflect the given points.
#
#
#     Example 1:
#
#
# Given points = [[1,1],[-1,1]], return true.
#
#
#
#     Example 2:
#
#
# Given points = [[1,1],[-1,-1]], return false.
#
#
# Follow up:
# Could you do better than O(n2)?
#
#
# Credits:Special thanks to @memoryless for adding this problem and creating all test cases.


class Solution(object):
    def canReflect(self, line_set):
        line = sorted(list(line_set))
        count = len(line)
        if count%2 == 0:
            right = line[count/2]
            left = line[count/2 - 1]
            mid = (right + left)/2.0
        else:
            mid = line[count/2]
        for i in range(count/2):
            left = line[i]
            right = line[count - i - 1]
            if mid - left != right - mid:
                return None
        return mid
        
    def isReflected(self, points):
        """
        :type points: List[List[int]]
        :rtype: bool
        """
        d = dict()
        for p in points:
            y = p[1]
            if y in d:
                d[y].add(p[0])
            else:
                d[y] = {p[0]}
        m = None
        for k in d:
            cur = self.canReflect(d[k])
            if cur is None:
                return False
            elif m is None:
                m = cur
            elif m != cur:
                return False
        return True
    
