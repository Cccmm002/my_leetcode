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
    int result;
    
    int UnivaluePath(TreeNode* root) {
        if (root == NULL) 
            return 0;
        int left = UnivaluePath(root->left);
        int right = UnivaluePath(root->right);
        int single_path = 1, current = 1;
        if (root->left != NULL && root->left->val == root->val) {
            single_path = max(single_path, 1 + left);
            current += left;
        }
        if (root->right != NULL && root->right->val == root->val) {
            single_path = max(single_path, 1 + right);
            current += right;
        }
        result = max(result, current);
        return single_path;
    }
    
public:
    int longestUnivaluePath(TreeNode* root) {
        if (root == NULL) return 0;
        result = 0;
        UnivaluePath(root);
        return result - 1;
    }
};
