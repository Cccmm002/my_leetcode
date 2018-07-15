// Given a binary search tree with non-negative values, find the minimum absolute difference between values of any two nodes.
//
//
// Example:
//
// Input:
//
//    1
//     \
//      3
//     /
//    2
//
// Output:
// 1
//
// Explanation:
// The minimum absolute difference is 1, which is the difference between 2 and 1 (or between 2 and 3).
//
//
//
//
// Note:
// There are at least two nodes in this BST.
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
 inline int min(int a, int b) { return a < b ? a : b; }
 
class Solution {
private:
    int result;
    
    int traverse(TreeNode *root, int prev) {
        if (root->left == NULL) {
            if (prev >= 0) {
                int diff = root->val - prev;
                result = min(diff, result);
            }
            if (root->right == NULL) {
                return root->val;
            }
            else {
                return traverse(root->right, root->val);
            }
        }
        int l = traverse(root->left, prev);
        int diff = root->val - l;
        result = min(diff, result);
        if (root->right == NULL) {
            return root->val;
        }
        else {
            return traverse(root->right, root->val);
        }
    }
    
public:
    int getMinimumDifference(TreeNode* root) {
        result = INT_MAX;
        traverse(root, -1);
        return result;
    }
};
