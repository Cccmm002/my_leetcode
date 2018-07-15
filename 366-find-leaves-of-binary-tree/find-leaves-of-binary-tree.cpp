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
    TreeNode* dfs(TreeNode* root, vector<int> &res) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root->val);
            return NULL;
        }
        else {
            root->left = dfs(root->left, res);
            root->right = dfs(root->right, res);
            return root;
        }
    }
    
public:
    vector<vector<int>> findLeaves(TreeNode* root) {
        vector<vector<int>> res;
        while (root != NULL) {
            vector<int> r;
            root = dfs(root, r);
            res.push_back(r);
        }
        return res;
    }
};
