# -*- coding:utf-8 -*-


# Serialization is the process of converting a data structure or object into a sequence of bits so that it can be stored in a file or memory buffer, or transmitted across a network connection link to be reconstructed later in the same or another computer environment. 
#
# Design an algorithm to serialize and deserialize a binary tree. There is no restriction on how your serialization/deserialization algorithm should work. You just need to ensure that a binary tree can be serialized to a string and this string can be deserialized to the original tree structure.
#
#
# For example, you may serialize the following tree
#
#     1
#    / \
#   2   3
#      / \
#     4   5
#
# as "[1,2,3,null,null,4,5]", just the same as how LeetCode OJ serializes a binary tree. You do not necessarily need to follow this format, so please be creative and come up with different approaches yourself.
#
#
#
# Note: Do not use class member/global/static variables to store states. Your serialize and deserialize algorithms should be stateless.
#
#
# Credits:Special thanks to @Louis1992 for adding this problem and creating all test cases.


# Definition for a binary tree node.
# class TreeNode(object):
#     def __init__(self, x):
#         self.val = x
#         self.left = None
#         self.right = None

class Codec:

    def serialize(self, root):
        """Encodes a tree to a single string.
        
        :type root: TreeNode
        :rtype: str
        """
        queue = []
        queue.append(root)
        pointer = 0
        while pointer < len(queue):
            cur = queue[pointer]
            if cur is not None:
                queue.append(cur.left)
                queue.append(cur.right)
            pointer += 1
        fl = list(map(lambda x: str(x.val) if x is not None else 'null', queue))
        return ','.join(fl)

    def deserialize(self, data):
        """Decodes your encoded data to tree.
        
        :type data: str
        :rtype: TreeNode
        """
        d = data.split(',')
        nodes = list(map(lambda x: TreeNode(int(x)) if x != 'null' else None, d))
        reverse = nodes[::-1]
        root = reverse.pop()
        for i in range(0, len(nodes)):
            if nodes[i] is not None:
                if len(reverse) > 0:
                    nodes[i].left = reverse.pop()
                if len(reverse) > 0:
                    nodes[i].right = reverse.pop()
        return root
        

# Your Codec object will be instantiated and called as such:
# codec = Codec()
# codec.deserialize(codec.serialize(root))
