# -*- coding:utf-8 -*-


# Given a time represented in the format "HH:MM", form the next closest time by reusing the current digits. There is no limit on how many times a digit can be reused.
#
# You may assume the given input string is always valid. For example, "01:34", "12:09" are all valid. "1:34", "12:9" are all invalid.
#
# Example 1:
#
# Input: "19:34"
# Output: "19:39"
# Explanation: The next closest time choosing from digits 1, 9, 3, 4, is 19:39, which occurs 5 minutes later.  It is not 19:33, because this occurs 23 hours and 59 minutes later.
#
#
#
# Example 2:
#
# Input: "23:59"
# Output: "22:22"
# Explanation: The next closest time choosing from digits 2, 3, 5, 9, is 22:22. It may be assumed that the returned time is next day's time since it is smaller than the input time numerically.
#
#


class Solution(object):
    def get_next(self, pool, current):
        n = len(current)
        p = n - 1
        while p >= 0:
            if current[p] == pool[-1]:
                p -= 1
                continue
            i = 0
            while i < len(pool):
                if current[p] == pool[i]:
                    break
                i += 1
            res = current[:]
            res[p] = pool[i + 1]
            for i in range(p + 1, n):
                res[i] = pool[0]
            return res
        return pool[0] * n
        
    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        l = list(time)
        del l[2]
        pool = sorted(list(set(l)))
        cur = l
        while True:
            nxt = self.get_next(pool, cur)
            hour = int(nxt[0] + nxt[1])
            minute = int(nxt[2] + nxt[3])
            if hour < 24 and minute < 60:
                return nxt[0] + nxt[1] + ':' + nxt[2] + nxt[3]
            else:
                cur = nxt
        
