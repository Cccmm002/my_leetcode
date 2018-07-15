# -*- coding:utf-8 -*-


#
# We are stacking blocks to form a pyramid.  Each block has a color which is a one letter string, like `'Z'`.
#
# For every block of color `C` we place not in the bottom row, we are placing it on top of a left block of color `A` and right block of color `B`.  We are allowed to place the block there only if `(A, B, C)` is an allowed triple.
#
# We start with a bottom row of bottom, represented as a single string.  We also start with a list of allowed triples allowed.  Each allowed triple is represented as a string of length 3.
#
# Return true if we can build the pyramid all the way to the top, otherwise false.
#
#
# Example 1:
#
# Input: bottom = "XYZ", allowed = ["XYD", "YZE", "DEA", "FFF"]
# Output: true
# Explanation:
# We can stack the pyramid like this:
#     A
#    / \
#   D   E
#  / \ / \
# X   Y   Z
#
# This works because ('X', 'Y', 'D'), ('Y', 'Z', 'E'), and ('D', 'E', 'A') are allowed triples.
#
#
#
# Example 2:
#
# Input: bottom = "XXYX", allowed = ["XXX", "XXY", "XYX", "XYY", "YXZ"]
# Output: false
# Explanation:
# We can't stack the pyramid to the top.
# Note that there could be allowed triples (A, B, C) and (A, B, D) with C != D.
#
#
#
# Note:
#
# bottom will be a string with length in range [2, 8].
# allowed will have length in range [0, 200].
# Letters in all strings will be chosen from the set {'A', 'B', 'C', 'D', 'E', 'F', 'G'}.
#
#


class Solution(object):
    def gen(self, bottom, d):
        if len(bottom) <= 1:
            return []
        res = []
        t = (bottom[0], bottom[1])
        if t not in d:
            return None
        if len(bottom) == 2:
            return list(d[t])
        nxt = self.gen(bottom[1:], d)
        if nxt is None:
            return None
        for c in d[t]:
            for nn in nxt:
                res.append(c + nn)
        return res
        
    def solve(self, bottom, d):
        n = len(bottom)
        if n == 1:
            return True
        nxt = self.gen(bottom, d)
        if nxt is None:
            return False
        for nn in nxt:
            if self.solve(nn, d):
                return True
        return False
        
    def pyramidTransition(self, bottom, allowed):
        """
        :type bottom: str
        :type allowed: List[str]
        :rtype: bool
        """
        d = dict()
        for tri in allowed:
            t = (tri[0], tri[1])
            if t not in d:
                d[t] = set()
            d[t].add(tri[2])
        return self.solve(bottom, d)
    
