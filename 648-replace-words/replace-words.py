# -*- coding:utf-8 -*-


#
# In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
#
#
#
#
# Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
#
#
#
# You need to output the sentence after the replacement.
#
#
#
# Example 1:
#
# Input: dict = ["cat", "bat", "rat"]
# sentence = "the cattle was rattled by the battery"
# Output: "the cat was rat by the bat"
#
#
#
#
# Note:
#
# The input will only have lower-case letters.
#  1 <= dict words number <= 1000 
#  1 <= sentence words number <= 1000  
#  1 <= root length <= 100 
#  1 <= sentence words length <= 1000 
#
#


class Solution(object):
    def replaceWords(self, _dict, sentence):
        """
        :type dict: List[str]
        :type sentence: str
        :rtype: str
        """
        d = set()
        for r in _dict:
            d.add(r)
        tokens = sentence.split(' ')
        res = []
        for t in tokens:
            n = len(t)
            put = t
            for i in range(n):
                cur = t[:i + 1]
                if cur in d:
                    put = cur
                    break
            res.append(put)
        return ' '.join(res)
    
