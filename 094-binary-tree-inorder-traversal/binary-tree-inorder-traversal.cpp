// Given a binary tree, return the inorder traversal of its nodes' values.
//
//
// For example:
// Given binary tree [1,null,2,3],
//
//    1
//     \
//      2
//     /
//    3
//
//
//
// return [1,3,2].
//
//
// Note: Recursive solution is trivial, could you do it iteratively?


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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> res;
        res.clear();
        if(root==NULL) return res;
        vector<int> l=inorderTraversal(root->left);
        vector<int> r=inorderTraversal(root->right);
        for(int i=0;i<l.size();i++)
            res.push_back(l[i]);
        res.push_back(root->val);
        for(int i=0;i<r.size();i++)
            res.push_back(r[i]);
        return res;
    }
};
