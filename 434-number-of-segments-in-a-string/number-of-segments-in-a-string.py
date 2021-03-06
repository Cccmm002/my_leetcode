# -*- coding:utf-8 -*-


# Count the number of segments in a string, where a segment is defined to be a contiguous sequence of non-space characters.
#
# Please note that the string does not contain any non-printable characters.
#
# Example:
#
# Input: "Hello, my name is John"
# Output: 5
#
#


class Solution(object):
    def countSegments(self, s):
        """
        :type s: str
        :rtype: int
        """
        t = s.split(' ')
        count = 0
        for x in t:
            if x != '':
                count += 1
        return count
        
