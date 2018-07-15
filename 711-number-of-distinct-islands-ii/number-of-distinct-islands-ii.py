# -*- coding:utf-8 -*-


# Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)  You may assume all four edges of the grid are surrounded by water.
#
# Count the number of distinct islands.  An island is considered to be the same as another if they have the same shape, or have the same shape after rotation (90, 180, or 270 degrees only) or reflection (left/right direction or up/down direction).
#
# Example 1:
#
# 11000
# 10000
# 00001
# 00011
#
# Given the above grid map, return 1.
#
# Notice that:
#
# 11
# 1
#
# and
#
#  1
# 11
#
# are considered same island shapes. Because if we make a 180 degrees clockwise rotation on the first island, then two islands will have the same shapes.
#
#
# Example 2:
#
# 11100
# 10001
# 01001
# 01110
# Given the above grid map, return 2.
#
# Here are the two distinct islands:
#
# 111
# 1
#
# and
#
# 1
# 1
#
#
# Notice that:
#
# 111
# 1
#
# and
#
# 1
# 111
#
# are considered same island shapes. Because if we flip the first array in the up/down direction, then they have the same shapes.
#
#
# Note:
# The length of each dimension in the given grid does not exceed 50.
#


class Solution(object):
    def numDistinctIslands2(self, grid):
        """
        :type grid: List[List[int]]
        :rtype: int
        """
        height = len(grid)
        if height == 0: return 0
        width = len(grid[0])
        visited = set()
        cur = set()
        res = set()
        self.res_count = 0
        
        def normalize(points): # points = {(x, y)}
            leftest = width
            wx = []
            for p in points:
                if leftest > p[1]:
                    leftest = p[1]
                    wx = [p]
                elif leftest == p[1]:
                    wx.append(p)
            highest = height
            for p in wx:
                highest = min(highest, p[0])
            res = set()
            for p in points:
                res.add((p[0] - highest, p[1] - leftest))
            return frozenset(res)
        
        def rotates(points):
            a, b, c, d, e, f = set(), set(), set(), set(), set(), set()
            for p in points:
                a.add((p[0], p[1]))
                b.add((-p[1], p[0]))
                c.add((-p[0], -p[1]))
                d.add((p[1], -p[0]))
                e.add((p[0], -p[1]))
                f.add((-p[0], p[1]))
            return [frozenset(a), normalize(b), normalize(c), normalize(d), normalize(e), normalize(f)]
        
        def find(h, w, h0, w0):
            if h < 0 or h >= height: return
            if w < 0 or w >= width: return
            if grid[h][w] != 1: return
            t = (h, w)
            if t in visited:
                return
            nt = (h - h0, w - w0)
            cur.add(nt)
            visited.add(t)
            find(h + 1, w, h0, w0)
            find(h - 1, w, h0, w0)
            find(h, w + 1, h0, w0)
            find(h, w - 1, h0, w0)
        
        def addSet(s):
            four = rotates(normalize(s))
            for f in four:
                if f in res:
                    return
            self.res_count += 1
            for f in four:
                res.add(f)
        
        for i in range(height):
            for j in range(width):
                cur.clear()
                find(i, j, i, j)
                if len(cur) > 0:
                    addSet(frozenset(cur))
        # print(len(res))
        return self.res_count
    
