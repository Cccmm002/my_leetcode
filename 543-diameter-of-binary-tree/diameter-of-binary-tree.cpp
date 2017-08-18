// Given a binary tree, you need to compute the length of the diameter of the tree. The diameter of a binary tree is the length of the longest path between any two nodes in a tree. This path may or may not pass through the root.
//
//
//
// Example:
// Given a binary tree 
//
//           1
//          / \
//         2   3
//        / \     
//       4   5    
//
//
//
// Return 3, which is the length of the path [4,2,1,3] or [5,2,1,3].
//
//
// Note:
// The length of path between two nodes is represented by the number of edges between them.


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
    int calc(TreeNode *root, int *cur_max) {
        if (root == NULL) return 0;
        int left = root->left == NULL ? 0 : calc(root->left, cur_max) + 1;
        int right = root->right == NULL ? 0 : calc(root->right, cur_max) + 1;
        int res = max(left, right);
        *cur_max = max(*cur_max, res);
        if (root->left != NULL && root->right != NULL) {
            int pass = left + right;
            *cur_max = max(*cur_max, pass);
        }
        return res;
    }
    
public:
    int diameterOfBinaryTree(TreeNode* root) {
        int res = 0;
        calc(root, &res);
        return res;
    }
};
