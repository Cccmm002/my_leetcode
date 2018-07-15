# -*- coding:utf-8 -*-


# Given a string s1, we may represent it as a binary tree by partitioning it to two non-empty substrings recursively.
#
# Below is one possible representation of s1 = "great":
#
#
#     great
#    /    \
#   gr    eat
#  / \    /  \
# g   r  e   at
#            / \
#           a   t
#
#
# To scramble the string, we may choose any non-leaf node and swap its two children.
#
# For example, if we choose the node "gr" and swap its two children, it produces a scrambled string "rgeat".
#
#
#     rgeat
#    /    \
#   rg    eat
#  / \    /  \
# r   g  e   at
#            / \
#           a   t
#
#
# We say that "rgeat" is a scrambled string of "great".
#
# Similarly, if we continue to swap the children of nodes "eat" and "at", it produces a scrambled string "rgtae".
#
#
#     rgtae
#    /    \
#   rg    tae
#  / \    /  \
# r   g  ta  e
#        / \
#       t   a
#
#
# We say that "rgtae" is a scrambled string of "great".
#
# Given two strings s1 and s2 of the same length, determine if s2 is a scrambled string of s1.
#
# Example 1:
#
#
# Input: s1 = "great", s2 = "rgeat"
# Output: true
#
#
# Example 2:
#
#
# Input: s1 = "abcde", s2 = "caebd"
# Output: false
#


class Solution(object):
    def isScramble(self, s1, s2):
        """
        :type s1: str
        :type s2: str
        :rtype: bool
        """
        len1 = len(s1)
        len2 = len(s2)
        record = dict()
        
        def solve(pos):  # pos = (i1, i2, l)
            if pos[2] == 1:
                return s1[pos[0]] == s2[pos[1]]
            if pos not in record:
                for k in range(1, pos[2]):
                    unswapped = solve((pos[0], pos[1], k)) and solve((pos[0] + k, pos[1] + k, pos[2] - k))
                    swapped = solve((pos[0], pos[1] + pos[2] - k, k)) and solve((pos[0] + k, pos[1], pos[2] - k))
                    if swapped or unswapped:
                        record[pos] = True
                        return True
                record[pos] = False
                return False
            else:
                return record[pos]
                
        return solve((0, 0, len1))
        
