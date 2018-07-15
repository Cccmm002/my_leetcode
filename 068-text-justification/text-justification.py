# -*- coding:utf-8 -*-


# Given an array of words and a width maxWidth, format the text such that each line has exactly maxWidth characters and is fully (left and right) justified.
#
# You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly maxWidth characters.
#
# Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
#
# For the last line of text, it should be left justified and no extra space is inserted between words.
#
# Note:
#
#
# 	A word is defined as a character sequence consisting of non-space characters only.
# 	Each word's length is guaranteed to be greater than 0 and not exceed maxWidth.
# 	The input array words contains at least one word.
#
#
# Example 1:
#
#
# Input:
# words = ["This", "is", "an", "example", "of", "text", "justification."]
# maxWidth = 16
# Output:
# [
#    "This    is    an",
#    "example  of text",
#    "justification.  "
# ]
#
#
# Example 2:
#
#
# Input:
# words = ["What","must","be","acknowledgment","shall","be"]
# maxWidth = 16
# Output:
# [
#   "What   must   be",
#   "acknowledgment  ",
#   "shall be        "
# ]
# Explanation: Note that the last line is "shall be    " instead of "shall     be",
#              because the last line must be left-justified instead of fully-justified.
#              Note that the second line is also left-justified becase it contains only one word.
#
#
# Example 3:
#
#
# Input:
# words = ["Science","is","what","we","understand","well","enough","to","explain",
#          "to","a","computer.","Art","is","everything","else","we","do"]
# maxWidth = 20
# Output:
# [
#   "Science  is  what we",
#   "understand      well",
#   "enough to explain to",
#   "a  computer.  Art is",
#   "everything  else  we",
#   "do                  "
# ]
#
#


class Solution(object):
    def fullJustify(self, words, maxWidth):
        """
        :type words: List[str]
        :type maxWidth: int
        :rtype: List[str]
        """
        res = []
        pointer = 0
        n = len(words)
        cur = []
        while pointer < n:
            nude_prev_sum = sum(list(map(lambda x: len(x), cur)))
            prev_sum = nude_prev_sum + len(cur) - 1
            next_sum = prev_sum + len(words[pointer]) + 1
            if next_sum <= maxWidth:
                cur.append(words[pointer])
                pointer += 1
            if next_sum == maxWidth:
                res.append(" ".join(cur))
                cur = []
            if next_sum > maxWidth:
                if len(cur) == 1:
                    st = cur[0]
                    remaining = maxWidth - len(st)
                    st += " "*remaining
                    res.append(st)
                else:
                    blank = maxWidth - nude_prev_sum
                    avg = blank / (len(cur) - 1)
                    mod = blank % (len(cur) - 1)
                    st = ""
                    for i in range(mod):
                        st += cur[i] + " "*(avg + 1)
                    for i in range(mod, len(cur) - 1):
                        st += cur[i] + " "*avg
                    st += cur[len(cur) - 1]
                    res.append(st)
                cur = []
        if len(cur) > 0:
            last_line = " ".join(cur)
            remaining = maxWidth - len(last_line)
            last_line += " "*remaining
            res.append(last_line)
        return res
    
