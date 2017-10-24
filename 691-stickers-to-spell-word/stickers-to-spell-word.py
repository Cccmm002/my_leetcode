# -*- coding:utf-8 -*-


# We are given N different types of stickers.  Each sticker has a lowercase English word on it.
#
# You would like to spell out the given target string by cutting individual letters from your collection of stickers and rearranging them.
#
# You can use each sticker more than once if you want, and you have infinite quantities of each sticker.
#
# What is the minimum number of stickers that you need to spell out the target?  If the task is impossible, return -1.
#
#
# Example 1:
# Input:
# ["with", "example", "science"], "thehat"
#
#
# Output:
# 3
#
#
# Explanation:
# We can use 2 "with" stickers, and 1 "example" sticker.
# After cutting and rearrange the letters of those stickers, we can form the target "thehat".
# Also, this is the minimum number of stickers necessary to form the target string.
#
#
# Example 2:
# Input:
# ["notice", "possible"], "basicbasic"
#
#
# Output:
# -1
#
#
# Explanation:
# We can't form the target "basicbasic" from cutting letters from the given stickers.
#
#
# Note:
# stickers has length in the range [1, 50].
# stickers consists of lowercase English words (without apostrophes).
# target has length in the range [1, 15], and consists of lowercase English letters.
# In all test cases, all words were chosen randomly from the 1000 most common US English words, and the target was chosen as a concatenation of two random words.
# The time limit may be more challenging than usual.  It is expected that a 50 sticker test case can be solved within 35ms on average.


class Solution(object):
    def minStickers(self, stickers, target):
        """
        :type stickers: List[str]
        :type target: str
        :rtype: int
        """
        record = dict()
        ss = [None for _ in range(len(stickers))]

        def getArr(s):
            c = collections.Counter(s)
            res = [0 for _ in range(26)]
            for k in c:
                i = ord(k) - ord('a')
                res[i] += c[k]
            return res

        for i in range(len(stickers)):
            ss[i] = getArr(stickers[i])

        def minus(target, s):
            res = target[:]
            for i in range(26):
                res[i] = max(0, target[i] - s[i])
            return res

        def opt(cur):
            zerot = tuple([0 for _ in range(26)])
            t = tuple(cur)
            if t == zerot:
                return 0
            if t in record:
                return record[t]
            res = float('inf')
            for i in range(len(stickers)):
                ppp = 0
                while cur[ppp] == 0: ppp += 1
                if ss[i][ppp] == 0: continue
                ncur = minus(cur, ss[i])
                if ncur == cur: continue
                res = min(res, opt(ncur) + 1)
            record[t] = res
            return res

        c = getArr(target)
        ts = set(target)
        set_s = set()
        for l in stickers:
            set_s = set_s.union(set(l))
        if len(ts - set_s) > 0: return -1
        return opt(c)

