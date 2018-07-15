# -*- coding:utf-8 -*-


#
# Find the minimum length word from a given dictionary words, which has all the letters from the string licensePlate.  Such a word is said to complete the given string licensePlate
#
# Here, for letters we ignore case.  For example, "P" on the licensePlate still matches "p" on the word.
#
# It is guaranteed an answer exists.  If there are multiple answers, return the one that occurs first in the array.
#
# The license plate might have the same letter occurring multiple times.  For example, given a licensePlate of "PP", the word "pair" does not complete the licensePlate, but the word "supper" does.
#
#
# Example 1:
#
# Input: licensePlate = "1s3 PSt", words = ["step", "steps", "stripe", "stepple"]
# Output: "steps"
# Explanation: The smallest length word that contains the letters "S", "P", "S", and "T".
# Note that the answer is not "step", because the letter "s" must occur in the word twice.
# Also note that we ignored case for the purposes of comparing whether a letter exists in the word.
#
#
#
# Example 2:
#
# Input: licensePlate = "1s3 456", words = ["looks", "pest", "stew", "show"]
# Output: "pest"
# Explanation: There are 3 smallest length words that contains the letters "s".
# We return the one that occurred first.
#
#
#
# Note:
#
# licensePlate will be a string with length in range [1, 7].
# licensePlate will contain digits, spaces, or letters (uppercase or lowercase).
# words will have a length in the range [10, 1000].
# Every words[i] will consist of lowercase letters, and have length in range [1, 15].
#
#


class Solution(object):
    def contains(self, pd, w):
        cd = collections.Counter(w)
        for k in pd:
            if k not in cd:
                return False
            if pd[k] > cd[k]:
                return False
        return True
        
    def shortestCompletingWord(self, licensePlate, words):
        """
        :type licensePlate: str
        :type words: List[str]
        :rtype: str
        """
        d = dict()
        licensePlate = licensePlate.lower()
        for i in range(len(licensePlate)):
            if licensePlate[i].isalpha():
                if licensePlate[i] not in d:
                    d[licensePlate[i]] = 0
                d[licensePlate[i]] += 1
        res = ''
        res_len = float('inf')
        for i in range(len(words)):
            cur = words[i].lower()
            if self.contains(d, cur):
                if res_len > len(cur):
                    res_len = len(cur)
                    res = words[i]
        return res
    
