# -*- coding:utf-8 -*-


# In the following, every capital letter represents some hexadecimal digit from 0 to f.
#
# The red-green-blue color "#AABBCC" can be written as "#ABC" in shorthand.  For example, "#15c" is shorthand for the color "#1155cc".
#
# Now, say the similarity between two colors "#ABCDEF" and "#UVWXYZ" is -(AB - UV)^2 - (CD - WX)^2 - (EF - YZ)^2.
#
# Given the color "#ABCDEF", return a 7 character color that is most similar to #ABCDEF, and has a shorthand (that is, it can be represented as some "#XYZ"
#
#
# Example 1:
# Input: color = "#09f166"
# Output: "#11ee66"
# Explanation:  
# The similarity is -(0x09 - 0x11)^2 -(0xf1 - 0xee)^2 - (0x66 - 0x66)^2 = -64 -9 -0 = -73.
# This is the highest among any shorthand color.
#
#
# Note:
#
#
# 	color is a string of length 7.
# 	color is a valid RGB color: for i > 0, color[i] is a hexadecimal digit from 0 to f
# 	Any answer which has the same (highest) similarity as the best answer will be accepted.
# 	All inputs and outputs should use lowercase letters, and the output is 7 characters.
#
#


class Solution(object):
    def find(self, n):
        cur = float('inf')
        res = None
        for i in range(16):
            test = i*16+i
            t = abs(test - n)
            if t < cur:
                cur = t
                res = i
        return res
    
    def toNum(self, s):
        return int(s, 16)
    
    def toHex(self, n):
        s = hex(n)
        return s[2:]
        
    def similarRGB(self, color):
        """
        :type color: str
        :rtype: str
        """
        a, b, c = self.toNum(color[1:3]), self.toNum(color[3:5]), self.toNum(color[5:])
        na, nb, nc = self.find(a), self.find(b), self.find(c)
        res = "#" + self.toHex(na)*2 + self.toHex(nb)*2 + self.toHex(nc)*2
        return res
        
