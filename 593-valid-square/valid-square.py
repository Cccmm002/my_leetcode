# -*- coding:utf-8 -*-


# Given the coordinates of four points in 2D space, return whether the four points could construct a square.
#
# The coordinate (x,y) of a point is represented by an integer array with two integers.
#
# Example:
#
# Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
# Output: True
#
#
#
#  Note: 
#
# All the input integers are in the range [-10000, 10000].
# A valid square has four equal sides with positive length and four equal angles (90-degree angles).
# Input points have no order.
#
#


class Solution(object):
    def vecdis2(self, vax, vay, vbx, vby):
        x = vbx - vax
        y = vby - vay
        return x*x + y*y
        
    def check_perp(self, p0, p1, p2):
        vax = p1[0] - p0[0]
        vay = p1[1] - p0[1]
        vbx = p2[0] - p0[0]
        vby = p2[1] - p0[1]
        return 0 == (vax*vbx + vay*vby)
        
    def validSquare(self, p1, p2, p3, p4):
        """
        :type p1: List[int]
        :type p2: List[int]
        :type p3: List[int]
        :type p4: List[int]
        :rtype: bool
        """
        d12 = self.vecdis2(p1[0], p1[1], p2[0], p2[1])
        d13 = self.vecdis2(p1[0], p1[1], p3[0], p3[1])
        d14 = self.vecdis2(p1[0], p1[1], p4[0], p4[1])
        d23 = self.vecdis2(p2[0], p2[1], p3[0], p3[1])
        d24 = self.vecdis2(p2[0], p2[1], p4[0], p4[1])
        d34 = self.vecdis2(p3[0], p3[1], p4[0], p4[1])
        if d12 == d13:
            if d24 == d34 and d24 == d12 and d24 != 0 and self.check_perp(p1, p2, p3) and self.check_perp(p4, p2, p3):
                return True
            else:
                return False
        elif d12 == d14:
            if d23 == d34 and d23 == d12 and d23 != 0 and self.check_perp(p1, p2, p4) and self.check_perp(p3, p4, p2):
                return True
            else:
                return False
        elif d13 == d14:
            if d23 == d24 and d23 == d13 and d23 != 0 and self.check_perp(p1, p3, p4) and self.check_perp(p2, p4, p3):
                return True
            else:
                return False
        else:
            return False

