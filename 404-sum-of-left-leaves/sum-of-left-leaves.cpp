// Find the sum of all left leaves in a given binary tree.
//
// Example:
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
// There are two left leaves in the binary tree, with values 9 and 15 respectively. Return 24.


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
    int sumOfLeftLeaves(TreeNode* root) {
        if (root == NULL || root->left == NULL && root->right == NULL)
            return 0;
        
        int sum = 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int len = q.size();
            for (int i = 0; i < len; i++) {
                TreeNode *cur = q.front();
                q.pop();
                if (cur->left != NULL && cur->left->left == NULL && cur->left->right == NULL)
                    sum += cur->left->val;
                if (cur->left != NULL) q.push(cur->left);
                if (cur->right != NULL) q.push(cur->right);
            }
        }
        return sum;
    }
};
