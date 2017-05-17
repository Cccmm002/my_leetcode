// Given a binary tree, find the maximum path sum.
//
//
// For this problem, a path is defined as any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The path must contain at least one node and does not need to go through the root.
//
//
// For example:
// Given the below binary tree,
//
//        1
//       / \
//      2   3
//
//
//
// Return 6.


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
    int globalMax = INT_MIN;
    
    int calc(TreeNode *root) {
        if (root == NULL) return 0;
        int left = calc(root->left);
        int right = calc(root->right);
        left = left > 0 ? left : 0;
        right = right > 0 ? right : 0;
        int lr = root->val + left + right;
        int cur = left > right ? left : right;
        globalMax = globalMax > lr ? globalMax : lr;
        return cur + root->val;
    }
    
public:
    int maxPathSum(TreeNode* root) {
        calc(root);
        return globalMax;
    }
};
