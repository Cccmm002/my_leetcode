// Given a binary tree, you need to find the length of Longest Consecutive Path in Binary Tree. 
//
// Especially, this path can be either increasing or decreasing. For example, [1,2,3,4] and [4,3,2,1] are both considered valid, but the path [1,2,4,3] is not valid. On the other hand, the path can be in the child-Parent-child order, where not necessarily be parent-child order.
//
// Example 1:
//
// Input:
//         1
//        / \
//       2   3
// Output: 2
// Explanation: The longest consecutive path is [1, 2] or [2, 1].
//
//
//
// Example 2:
//
// Input:
//         2
//        / \
//       1   3
// Output: 3
// Explanation: The longest consecutive path is [1, 2, 3] or [3, 2, 1].
//
//
//
// Note:
// All the values of tree nodes are in the range of [-1e7, 1e7].
//
//
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
    
    pair<int, int> dfs(TreeNode *root) {    // increment, decrement
        if (root == NULL)
            return make_pair(0, 0);
        int incr = 1, decr = 1;
        pair<int, int> left_pair = dfs(root->left);
        pair<int, int> right_pair = dfs(root->right);
        int left_incr = left_pair.first, left_decr = left_pair.second;
        int right_incr = right_pair.first, right_decr = right_pair.second;
        if (root->left != NULL && root->left->val - 1 == root->val)
            incr = max(incr, left_incr + 1);
        if (root->left != NULL && root->left->val + 1 == root->val)
            decr = max(decr, left_decr + 1);
        if (root->right != NULL && root->right->val - 1 == root->val)
            incr = max(incr, right_incr + 1);
        if (root->right != NULL && root->right->val + 1 == root->val)
            decr = max(decr, right_decr + 1);
        result = max(result, incr + decr - 1);
        return make_pair(incr, decr);
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        result = 0;
        dfs(root);
        return result;
    }
};
