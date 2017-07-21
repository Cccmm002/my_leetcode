// Given a binary tree, count the number of uni-value subtrees.
// A Uni-value subtree means all nodes of the subtree have the same value.
//
//
// For example:
// Given binary tree,
//
//               5
//              / \
//             1   5
//            / \   \
//           5   5   5
//
//
//
// return 4.


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
    void calc(TreeNode* root, int *count, bool *uni) {
        if (root->left == NULL && root->right == NULL) {
            *uni = true;
            *count = 1;
            return;
        }
        int left_count, right_count;
        bool left_uni, right_uni;
        if (root->left != NULL)
            calc(root->left, &left_count, &left_uni);
        if (root->right != NULL)
            calc(root->right, &right_count, &right_uni);
        if (root->left == NULL) {
            if (root->right->val == root->val && right_uni) {
                *count = right_count + 1;
                *uni = true;
            }
            else {
                *count = right_count;
                *uni = false;
            }
        }
        else if (root->right == NULL) {
            if (root->left->val == root->val && left_uni) {
                *count = left_count + 1;
                *uni = true;
            }
            else {
                *count = left_count;
                *uni = false;
            }
        }
        else {
            if (root->left->val == root->val && left_uni && root->right->val == root->val && right_uni) {
                *count = left_count + right_count + 1;
                *uni = true;
            }
            else {
                *count = left_count + right_count;
                *uni = false;
            }
        }
    }
    
public:
    int countUnivalSubtrees(TreeNode* root) {
        if (root == NULL) return 0;
        int count;
        bool uni;
        calc(root, &count, &uni);
        return count;
    }
};
