// Given a binary tree, collect a tree's nodes as if you were doing this: Collect and remove all leaves, repeat until the tree is empty.
//
//
//
// Example:
// Given binary tree 
//
//           1
//          / \
//         2   3
//        / \     
//       4   5    
//
//
//
// Returns [4, 5, 3], [2], [1].
//
//
//
// Explanation:
//
// 1. Removing the leaves [4, 5, 3] would result in this tree:
//
//           1
//          / 
//         2          
//
//
//
// 2. Now removing the leaf [2] would result in this tree:
//
//           1          
//
//
//
// 3. Now removing the leaf [1] would result in the empty tree:
//
//           []         
//
//
//
//
// Returns [4, 5, 3], [2], [1].
//
//
// Credits:Special thanks to @elmirap for adding this problem and creating all test cases.


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
    void traversal(TreeNode *root, vector<int> &res, TreeNode *parent, bool left) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            if (parent != NULL) {
                if (left) parent->left = NULL;
                else parent->right = NULL;
            }
            return;
        }
        traversal(root->left, res, root, true);
        traversal(root->right, res, root, false);
    }
    
    vector<int> leaves(TreeNode *root) {
        vector<int> res;
        traversal(root, res, NULL, true);
        return res;
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        if (root == NULL) return res;
        while (root->left != NULL || root->right != NULL) {
            res.push_back(leaves(root));
        }
        vector<int> one = {root->val};
        res.push_back(one);
        return res;
    }
};
