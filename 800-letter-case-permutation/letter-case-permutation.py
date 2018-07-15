# -*- coding:utf-8 -*-


# Given a string S, we can transform every letter individually to be lowercase or uppercase to create another string.  Return a list of all possible strings we could create.
#
#
# Examples:
# Input: S = "a1b2"
# Output: ["a1b2", "a1B2", "A1b2", "A1B2"]
#
# Input: S = "3z4"
# Output: ["3z4", "3Z4"]
#
# Input: S = "12345"
# Output: ["12345"]
#
#
# Note:
#
#
# 	S will be a string with length at most 12.
# 	S will consist only of letters or digits.
#


class Solution(object):
    def letterCasePermutation(self, S):
        n = len(S)
        if n == 0:
            return [""]
        nxts = self.letterCasePermutation(S[1:])
        cur = S[0]
        if cur.isdigit():
            res = [cur + st for st in nxts]
            return res
        else:
            cur_lower = cur.lower()
            cur_upper = cur.upper()
            res_lower = [cur_lower + st for st in nxts]
            res_upper = [cur_upper + st for st in nxts]
            return res_lower + res_upper
        
