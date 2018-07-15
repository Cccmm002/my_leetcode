# -*- coding:utf-8 -*-


# There are N dominoes in a line, and we place each domino vertically upright.
#
# In the beginning, we simultaneously push some of the dominoes either to the left or to the right.
#
#
#
# After each second, each domino that is falling to the left pushes the adjacent domino on the left.
#
# Similarly, the dominoes falling to the right push their adjacent dominoes standing on the right.
#
# When a vertical domino has dominoes falling on it from both sides, it stays still due to the balance of the forces.
#
# For the purposes of this question, we will consider that a falling domino expends no additional force to a falling or already fallen domino.
#
# Given a string "S" representing the initial state. S[i] = 'L', if the i-th domino has been pushed to the left; S[i] = 'R', if the i-th domino has been pushed to the right; S[i] = '.', if the i-th domino has not been pushed.
#
# Return a string representing the final state. 
#
# Example 1:
#
#
# Input: ".L.R...LR..L.."
# Output: "LL.RR.LLRRLL.."
#
#
# Example 2:
#
#
# Input: "RR.L"
# Output: "RR.L"
# Explanation: The first domino expends no additional force on the second domino.
#
#
# Note:
#
#
# 	0 <= N <= 10^5
# 	String dominoes contains only 'L', 'R' and '.'
#


class Solution(object):
    def pushDominoes(self, dominoes):
        """
        :type dominoes: str
        :rtype: str
        """
        n = len(dominoes)
        l = list(dominoes)
        fall = [(-1, 'L')] + [(i, l[i]) for i in range(n) if l[i] != '.'] + [(n, 'R')]
        for i in range(len(fall) - 1):
            if fall[i + 1][0] - fall[i][0] <= 1:
                continue
            if fall[i + 1][1] == fall[i][1]:
                for k in range(fall[i][0] + 1, fall[i + 1][0]):
                    l[k] = fall[i][1]
            elif fall[i][1] == 'R':
                left = fall[i][0] + 1
                right = fall[i + 1][0] - 1
                while left < right:
                    l[left] = 'R'
                    l[right] = 'L'
                    left += 1
                    right -= 1
        return "".join(l)
        
