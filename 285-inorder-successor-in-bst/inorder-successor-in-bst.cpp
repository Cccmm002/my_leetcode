// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
// Note: If the given node has no in-order successor in the tree, return null.
//
// Example 1:
//
//
// Input: root = [2,1,3], p = 1
//
//   2
//  / \
// 1   3
//
// Output: 2
//
// Example 2:
//
//
// Input: root = [5,3,6,2,4,null,null,1], p = 6
//
//       5
//      / \
//     3   6
//    / \
//   2   4
//  /   
// 1
//
// Output: null
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
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL) return NULL;
        if (p->right != NULL) {
            TreeNode* cur = p->right;
            while (cur->left != NULL) cur = cur->left;
            return cur;
        }
        stack<pair<TreeNode*, bool>> s;
        TreeNode* current = root;
        while (current != p) {
            if (current->val > p->val) {
                s.push(make_pair(current, false));
                current = current->left;
            }
            else {
                s.push(make_pair(current, true));
                current = current->right;
            }
            if (current == NULL) return NULL;
        }
        TreeNode *n = NULL;
        while (!s.empty()) {
            pair<TreeNode*, bool> node = s.top();
            s.pop();
            if (!node.second) {
                n = node.first;
                break;
            }
        }
        return n;
    }
};
