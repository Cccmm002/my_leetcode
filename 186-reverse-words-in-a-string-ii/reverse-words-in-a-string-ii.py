# -*- coding:utf-8 -*-


# Given an input string , reverse the string word by word. 
#
# Example:
#
#
# Input:  ["t","h","e"," ","s","k","y"," ","i","s"," ","b","l","u","e"]
# Output: ["b","l","u","e"," ","i","s"," ","s","k","y"," ","t","h","e"]
#
# Note: 
#
#
# 	A word is defined as a sequence of non-space characters.
# 	The input string does not contain leading or trailing spaces.
# 	The words are always separated by a single space.
#
#
# Follow up: Could you do it in-place without allocating extra space?
#


class Solution:
    # @param s, a list of 1 length strings, e.g., s = ['h','e','l','l','o']
    # @return nothing
    def reverseWords(self, s):
        s[:] = s[::-1]
        n = len(s)
        i = 0
        prev = 0
        while i <= n:
            if i == n or s[i] == ' ':
                s[prev:i] = s[prev:i][::-1]
                prev = i + 1
            i += 1
        
