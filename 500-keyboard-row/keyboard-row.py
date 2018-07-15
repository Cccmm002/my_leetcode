# -*- coding:utf-8 -*-


# Given a List of words, return the words that can be typed using letters of alphabet on only one row's of American keyboard like the image below. 
#
#
#
#
#
#
#
# Example 1:
#
# Input: ["Hello", "Alaska", "Dad", "Peace"]
# Output: ["Alaska", "Dad"]
#
#
#
# Note:
#
# You may use one character in the keyboard more than once.
# You may assume the input string will only contain letters of alphabet.
#
#


class Solution(object):
    def findWords(self, words):
        """
        :type words: List[str]
        :rtype: List[str]
        """
        alpha = {'a':1,'b':2,'c':2,'d':1,'e':0,'f':1,'g':1,'h':1,'i':0,'j':1,'k':1,'l':1,'m':2,'n':2,'o':0,'p':0,'q':0,'r':0,'s':1,'t':0,'u':0,'v':2,'w':0,'x':2,'y':0,'z':2}
        res = []
        for word in words:
            w = word.lower()
            row = alpha[w[0]]
            put = True
            for i in range(1, len(w)):
                if row != alpha[w[i]]:
                    put = False
                    break
            if put:
                res.append(word)
        return res
    
