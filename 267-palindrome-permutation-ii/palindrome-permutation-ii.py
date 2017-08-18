# -*- coding:utf-8 -*-


# Given a string s, return all the palindromic permutations (without duplicates) of it. Return an empty list if no palindromic permutation could be form.
#
#
# For example:
#
#
# Given s = "aabb", return ["abba", "baab"].
#
#
# Given s = "abc", return [].


class Solution(object):
    def calc(self, d):
        if len(d) == 0: return [""]
        if len(d) == 1 and d[d.keys()[0]] == 1: return [d.keys()[0]]
        res = set()
        for k in d:
            if d[k] == 1: continue
            nxt = dict(d)
            nxt[k] -= 2
            if nxt[k] == 0: del nxt[k]
            nl = self.calc(nxt)
            for s in nl:
                res.add(k + s + k)
        return list(res)
        
    def generatePalindromes(self, s):
        """
        :type s: str
        :rtype: List[str]
        """
        d = dict()
        for c in s:
            if c in d:
                d[c] += 1
            else:
                d[c] = 1
        odd = 0
        for k in d:
            if d[k] % 2 == 1:
                odd += 1
        if odd > 1:
            return []
        return self.calc(d)
    
