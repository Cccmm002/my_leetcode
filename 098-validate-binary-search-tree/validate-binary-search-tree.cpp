// Given a binary tree, determine if it is a valid binary search tree (BST).
//
//
//
// Assume a BST is defined as follows:
//
// The left subtree of a node contains only nodes with keys less than the node's key.
// The right subtree of a node contains only nodes with keys greater than the node's key.
// Both the left and right subtrees must also be binary search trees.
//
//
//
// Example 1:
//
//     2
//    / \
//   1   3
//
// Binary tree [2,1,3], return true.
//
//
// Example 2:
//
//     1
//    / \
//   2   3
//
// Binary tree [1,2,3], return false.


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
    struct BST {
        TreeNode *root;
        int max,min;
        bool isBST;
        BST(TreeNode *r) : root(r),isBST(true) {}
    };
    
    BST recursion(TreeNode* root) {
        BST res(root);
        if(root->left==NULL && root->right==NULL) {
            res.max=root->val;
            res.min=root->val;
            return res;
        }
        BST left(NULL);
        BST right(NULL);
        if(root->left!=NULL) left=recursion(root->left);
        if(root->right!=NULL) right=recursion(root->right);
        if(root->left==NULL){
            res.isBST=right.isBST && right.min>root->val;
            res.max=right.max;
            res.min=root->val;
            return res;
        }
        if(root->right==NULL){
            res.isBST=left.isBST && left.max<root->val;
            res.max=root->val;
            res.min=left.min;
            return res;
        }
        res.isBST=left.isBST && right.isBST && right.min>root->val && left.max<root->val;
        res.max=right.max;
        res.min=left.min;
        return res;
    }
    
public:
    bool isValidBST(TreeNode* root) {
        if(root==NULL) return true;
        BST res=recursion(root);
        return res.isBST;
    }
};
