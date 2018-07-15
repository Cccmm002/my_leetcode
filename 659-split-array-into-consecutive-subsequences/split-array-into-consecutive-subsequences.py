# -*- coding:utf-8 -*-


# You are given an integer array sorted in ascending order (may contain duplicates), you need to split them into several subsequences, where each subsequences consist of at least 3 consecutive integers. Return whether you can make such a split.
#
# Example 1:
#
# Input: [1,2,3,3,4,5]
# Output: True
# Explanation:
# You can split them into two consecutive subsequences : 
# 1, 2, 3
# 3, 4, 5
#
#
#
# Example 2:
#
# Input: [1,2,3,3,4,4,5,5]
# Output: True
# Explanation:
# You can split them into two consecutive subsequences : 
# 1, 2, 3, 4, 5
# 3, 4, 5
#
#
#
# Example 3:
#
# Input: [1,2,3,4,4,5]
# Output: False
#
#
#
# Note:
#
# The length of the input is in range of [1, 10000]
#
#


class Solution(object):
    def isPossible(self, nums):
        """
        :type nums: List[int]
        :rtype: bool
        """
        d = dict()
        for n in nums:
            if n in d:
                d[n] += 1
            else:
                d[n] = 1
        k = d.keys()
        s = min(k)
        l = max(k)
        items = [i for i in range(s, l + 1)]
        n = len(items)
        for i in items:
            if i not in d:
                d[i] = 0
        start = [items[0] for _ in range(d[items[0]])]
        end = []
        for i in range(n - 1):
            if d[items[i + 1]] > d[items[i]]:
                for j in range(d[items[i + 1]] - d[items[i]]):
                    start.append(items[i + 1])
            elif d[items[i + 1]] < d[items[i]]:
                for j in range(d[items[i]] - d[items[i + 1]]):
                    end.append(items[i])
        for i in range(d[items[n - 1]]):
            end.append(items[n - 1])
        if len(start) != len(end):
            return False
        for i in range(len(start)):
            if end[i] - start[i] < 2:
                return False
        return True
        
