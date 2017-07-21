// Given a binary tree, find the length of the longest consecutive sequence path.
//
//
// The path refers to any sequence of nodes from some starting node to any node in the tree along the parent-child connections. The longest consecutive path need to be from parent to child (cannot be the reverse).
//
//
//
// For example,
//
//    1
//     \
//      3
//     / \
//    2   4
//         \
//          5
//
// Longest consecutive sequence path is 3-4-5, so return 3. 
//
//    2
//     \
//      3
//     / 
//    2    
//   / 
//  1
//
// Longest consecutive sequence path is 2-3,not3-2-1, so return 2.


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
    int calc(TreeNode *root, int current, int target) {
        if (root == NULL) return current;
        if (root->val != target) {
            current = 1;
        }
        else {
            ++current;
        }
        int left = calc(root->left, current, root->val + 1);
        int right = calc(root->right, current, root->val + 1);
        return max(max(left, right), current);
    }
    
public:
    int longestConsecutive(TreeNode* root) {
        if (root == NULL) return 0;
        int left = calc(root->left, 1, root->val + 1);
        int right = calc(root->right, 1, root->val + 1);
        return max(left, right);
    }
};
