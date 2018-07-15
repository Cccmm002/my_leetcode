# -*- coding:utf-8 -*-


# You are given a string, s, and a list of words, words, that are all of the same length. Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
#
# Example 1:
#
#
# Input:
#   s = "barfoothefoobarman",
#   words = ["foo","bar"]
# Output: [0,9]
# Explanation: Substrings starting at index 0 and 9 are "barfoor" and "foobar" respectively.
# The output order does not matter, returning [9,0] is fine too.
#
#
# Example 2:
#
#
# Input:
#   s = "wordgoodstudentgoodword",
#   words = ["word","student"]
# Output: []
#
#


class Solution(object):
    def findSubstring(self, s, words):
        """
        :type s: str
        :type words: List[str]
        :rtype: List[int]
        """
        res = []
        ws = dict()
        for ss in words:
            if ss in ws:
                ws[ss] += 1
            else:
                ws[ss] = 1
        wl = len(words[0])
        tl = len(words) * wl
        for i in range(0, len(s) - tl + 1):
            existed = dict()
            flag = True
            for j in range(i, i+tl, wl):
                curs = s[j:j+wl]
                if curs not in ws:
                    flag = False
                    break
                if curs in existed:
                    if existed[curs] < ws[curs]:
                        existed[curs] += 1
                    else:
                        flag = False
                        break
                else:
                    existed[curs] = 1
            if flag:
                res.append(i)
        return res
        
