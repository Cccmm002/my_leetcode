// Given a binary tree, find the length of the longest path where each node in the path has the same value. This path may or may not pass through the root.
//
// Note: The length of path between two nodes is represented by the number of edges between them.
//
//
// Example 1:
//
//
//
//
// Input:
//
//               5
//              / \
//             4   5
//            / \   \
//           1   1   5
//
//
//
//
// Output:
//
// 2
//
//
//
//
// Example 2:
//
//
//
//
// Input:
//
//               1
//              / \
//             4   5
//            / \   \
//           4   4   5
//
//
//
//
// Output:
//
// 2
//
//
//
// Note:
// The given binary tree has not more than 10000 nodes.  The height of the tree is not more than 1000.


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
    int forRoot(TreeNode *root, int prev) {
        if (root == NULL) return 0;
        if (root->val != prev) return 0;
        return max(forRoot(root->left, prev), forRoot(root->right, prev)) + 1;
    }
    
    int nonForRoot(TreeNode *root) {
        if (root == NULL) return 0;
        int rt = forRoot(root->left, root->val) + forRoot(root->right, root->val) + 1;
        int left = nonForRoot(root->left);
        int right = nonForRoot(root->right);
        return max(rt, max(left, right));
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        return nonForRoot(root) - 1;
    }
};
