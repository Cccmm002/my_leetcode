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


class Solution(object):
    def genTwoDigits(self, s):
        res = []
        for a in s:
            for b in s:
                res.append(a * 10 + b)
        return res

    def genTime(self, digits):
        res = []
        td = self.genTwoDigits(digits)
        for hh in td:
            if hh >= 24: continue
            for mm in td:
                if mm >= 60: continue
                res.append((hh, mm))
        return res
    
    def to_string(self, digits):
        res = str(digits)
        if len(res) == 1:
            return '0' + res
        else:
            return res

    def nextClosestTime(self, time):
        """
        :type time: str
        :rtype: str
        """
        digits = set()
        for c in time:
            if c == ':': continue
            digits.add(int(c))
        times = self.genTime(digits)
        l_time = time.split(':')
        t_time = (int(l_time[0]), int(l_time[1]))

        def my_cmp(a, b):
            if a[0] < b[0]:
                return -1
            elif a[0] > b[0]:
                return 1
            if a[1] < b[1]:
                return -1
            elif a[1] > b[1]:
                return 1

        times.sort(cmp=my_cmp)
        for i in range(len(times)):
            if my_cmp(times[i], t_time) >= 1:
                return self.to_string(times[i][0]) + ':' + self.to_string(times[i][1])
        return self.to_string(times[0][0]) + ':' + self.to_string(times[0][1])
    
