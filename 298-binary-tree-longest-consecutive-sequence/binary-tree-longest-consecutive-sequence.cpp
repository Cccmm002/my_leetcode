// Given a binary tree, find the length of the longest consecutive sequence path.
//
// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
// Example 1:
//
//
// Input:
//
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
//
// Output: 3
//
// Explanation: Longest consecutive sequence path is 3-4-5, so return 3.
//
// Example 2:
//
//
// Input:
//
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
//
// Output: 2 
//
// Explanation: Longest consecutive sequence path is 2-3, not 3-2-1, so return 2.
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
    int res;
    
    int consecutive(TreeNode *root) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) {
            res = max(res, 1);
            return 1;
        }
        int left = consecutive(root->left) + 1;
        int right = consecutive(root->right) + 1;
        if (root->left != NULL && root->left->val != root->val + 1)
            left = 1;
        if (root->right != NULL && root->right->val != root->val + 1)
            right = 1;
        int r = max(left, right);
        res = max(res, r);
        return r;
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        res = 0;
        consecutive(root);
        return res;
    }
};
