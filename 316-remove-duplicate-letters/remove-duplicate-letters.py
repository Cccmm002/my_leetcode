# -*- coding:utf-8 -*-


# Given a string which contains only lowercase letters, remove duplicate letters so that every letter appear once and only once. You must make sure your result is the smallest in lexicographical order among all possible results.
#
# Example 1:
#
#
# Input: "bcabc"
# Output: "abc"
#
#
# Example 2:
#
#
# Input: "cbacdcbc"
# Output: "acdb"
#
#


class Solution(object):
    def removeDuplicateLetters(self, s):
        """
        :type s: str
        :rtype: str
        """
        n = len(s)
        if n == 0: return ''
        c = collections.Counter(s)
        cur_min = None
        cur_min_loc = -1
        for i in range(n):
            if c[s[i]] >= 1:
                c[s[i]] -= 1
                if cur_min is None or cur_min > s[i]:
                    cur_min = s[i]
                    cur_min_loc = i
                if c[s[i]] == 0: break
            else:
                break
        nxt = s[cur_min_loc + 1:].replace(cur_min, '')
        return cur_min + self.removeDuplicateLetters(nxt)
    
