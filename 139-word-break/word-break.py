# -*- coding:utf-8 -*-


# Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words. You may assume the dictionary does not contain duplicate words.
#
#
# For example, given
# s = "leetcode",
# dict = ["leet", "code"].
#
#
#
# Return true because "leetcode" can be segmented as "leet code".
#
#
#
# UPDATE (2017/1/4):
# The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.


class Solution(object):
    def wordBreak(self, s, wordDict):
        """
        :type s: str
        :type wordDict: List[str]
        :rtype: bool
        """
        record = dict()
        
        def solve(i, j):
            t = (i ,j)
            if t in record:
                return record[t]
            if s[i:j+1] in wordDict:
                record[t] = True
                return True
            for k in range(i,j):
                if solve(i, k) and solve(k + 1, j):
                    record[t] = True
                    return True
            record[t] = False
            return False
        
        return solve(0, len(s) - 1)
        
