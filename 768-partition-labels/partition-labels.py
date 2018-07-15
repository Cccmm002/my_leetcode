# -*- coding:utf-8 -*-


#
# A string S of lowercase letters is given.  We want to partition this string into as many parts as possible so that each letter appears in at most one part, and return a list of integers representing the size of these parts.
#
#
# Example 1:
#
# Input: S = "ababcbacadefegdehijhklij"
# Output: [9,7,8]
# Explanation:
# The partition is "ababcbaca", "defegde", "hijhklij".
# This is a partition so that each letter appears in at most one part.
# A partition like "ababcbacadefegde", "hijhklij" is incorrect, because it splits S into less parts.
#
#
#
# Note:
# S will have length in range [1, 500].
# S will consist of lowercase letters ('a' to 'z') only.
#


class Solution(object):
    def partitionLabels(self, S):
        """
        :type S: str
        :rtype: List[int]
        """
        letters = dict()
        for i in range(len(S)):
            if S[i] not in letters:
                letters[S[i]] = [i, i]
            else:
                letters[S[i]][1] = i
        intervals = []
        for k in letters:
            intervals.append((letters[k][0], letters[k][1]))
        intervals.sort()
        res = []
        current_begin = intervals[0][0]
        current_end = intervals[0][1]
        for i in range(1, len(intervals)):
            if (intervals[i][0] <= current_end):
                current_end = max(intervals[i][1], current_end)
            else:
                res.append(current_end - current_begin + 1)
                current_begin = intervals[i][0]
                current_end = intervals[i][1]
        res.append(current_end - current_begin + 1)
        return res
    
