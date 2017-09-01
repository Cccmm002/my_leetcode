# -*- coding:utf-8 -*-


# Given an array of words and a length L, format the text such that each line has exactly L characters and is fully (left and right) justified.
#
#
#
# You should pack your words in a greedy approach; that is, pack as many words as you can in each line. Pad extra spaces ' ' when necessary so that each line has exactly L characters.
#
#
#
# Extra spaces between words should be distributed as evenly as possible. If the number of spaces on a line do not divide evenly between words, the empty slots on the left will be assigned more spaces than the slots on the right.
#
#
#
# For the last line of text, it should be left justified and no extra space is inserted between words.
#
#
#
# For example,
# words: ["This", "is", "an", "example", "of", "text", "justification."]
# L: 16.
#
#
#
# Return the formatted lines as:
#
# [
#    "This    is    an",
#    "example  of text",
#    "justification.  "
# ]
#
#
#
#
# Note: Each word is guaranteed not to exceed L in length.
#
#
#
# click to show corner cases.
#
# Corner Cases:
#
#
# A line other than the last line might contain only one word. What should you do in this case?
# In this case, that line should be left-justified.


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
    
