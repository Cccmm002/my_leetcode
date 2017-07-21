// Given a binary tree where all the right nodes are either leaf nodes with a sibling (a left node that shares the same parent node) or empty, flip it upside down and turn it into a tree where the original right nodes turned into left leaf nodes. Return the new root.
//
//
// For example:
// Given a binary tree {1,2,3,4,5},
//
//     1
//    / \
//   2   3
//  / \
// 4   5
//
//
//
// return the root of the binary tree [4,5,2,#,#,3,1].
//
//    4
//   / \
//  5   2
//     / \
//    3   1  
//
//
//
// confused what "{1,#,2,3}" means? > read more on how binary tree is serialized on OJ.
//
// OJ's Binary Tree Serialization:
//
// The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
//
//
// Here's an example:
//
//    1
//   / \
//  2   3
//     /
//    4
//     \
//      5
//
// The above binary tree is serialized as "{1,2,3,#,#,4,#,#,5}".


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    TreeNode* upsideDownBinaryTree(TreeNode* root) {
        if (root == NULL) return NULL;
        TreeNode *prevLeft = NULL;
        TreeNode *prevRight = NULL;
        TreeNode *cur = root;
        while (cur != NULL) {
            TreeNode *left = cur->left;
            TreeNode *right = cur->right;
            cur->left = prevLeft;
            cur->right = prevRight;
            prevLeft = right;
            prevRight = cur;
            cur = left;
        }
        return prevRight;
    }
};
