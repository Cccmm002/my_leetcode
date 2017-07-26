// Given a non-empty binary search tree and a target value, find the value in the BST that is closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You are guaranteed to have only one unique value in the BST that is closest to the target.


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
    int closestValue(TreeNode* root, double target) {
        if (root == NULL) return 0;
        if (root->left == NULL && root->right == NULL) return root->val;
        int cur = root->val;
        if (root->left != NULL) {
            int next = closestValue(root->left, target);
            double a = abs((double)cur - target);
            double b = abs((double)next - target);
            if (b < a) cur = next;
        }
        if (root->right != NULL) {
            int next = closestValue(root->right, target);
            double a = abs((double)cur - target);
            double b = abs((double)next - target);
            if (b < a) cur = next;
        }
        return cur;
    }
};
