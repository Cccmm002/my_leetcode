# -*- coding:utf-8 -*-


#
# Given an arbitrary ransom note string and another string containing letters from all the magazines, write a function that will return true if the ransom 
# note can be constructed from the magazines ; otherwise, it will return false. 
#
#
# Each letter in the magazine string can only be used once in your ransom note.
#
#
# Note:
# You may assume that both strings contain only lowercase letters.
#
#
#
# canConstruct("a", "b") -> false
# canConstruct("aa", "ab") -> false
# canConstruct("aa", "aab") -> true
#
#


class Solution(object):
    def canConstruct(self, ransomNote, magazine):
        """
        :type ransomNote: str
        :type magazine: str
        :rtype: bool
        """
        maga = dict()
        for i in range(len(magazine)):
            if magazine[i] in maga:
                maga[magazine[i]] += 1
            else:
                maga[magazine[i]] = 1
        
        note = dict()
        for i in range(len(ransomNote)):
            if ransomNote[i] in note:
                note[ransomNote[i]] += 1
            else:
                note[ransomNote[i]] = 1
        
        for k, v in note.items():
            if not k in maga:
                return False
            else:
                if maga[k] < v:
                    return False
        
        return True
