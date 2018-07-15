// Given a complete binary tree, count the number of nodes.
//
// Note: 
//
// Definition of a complete binary tree from Wikipedia:
// In a complete binary tree every level, except possibly the last, is completely filled, and all nodes in the last level are as far left as possible. It can have between 1 and 2h nodes inclusive at the last level h.
//
// Example:
//
//
// Input: 
//     1
//    / \
//   2   3
//  / \  /
// 4  5 6
//
// Output: 6
//


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
private:
    inline int height(TreeNode *root) {
        int res = 0;
        TreeNode *cur = root;
        while (cur != NULL) {
            ++res;
            cur = cur->left;
        }
        return res;
    }
    
public:
    int countNodes(TreeNode* root) {
        int h = height(root);
        if (h == 0) return 0;
        if (h == 1) return 1;
        int lh = height(root->left);
        int rh = height(root->right);
        if (lh == rh) {
            return pow(2, lh) + countNodes(root->right);
        }
        else {
            return countNodes(root->left) + pow(2, rh);
        }
    }
};
