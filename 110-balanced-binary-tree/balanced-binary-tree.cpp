// Given a binary tree, determine if it is height-balanced.
//
//
//
// For this problem, a height-balanced binary tree is defined as a binary tree in which the depth of the two subtrees of every node never differ by more than 1.


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
    int height(TreeNode* root){
        if(root==NULL) return 0;
        int l,r;
        l=height(root->left);
        if(l==-1) return -1;
        r=height(root->right);
        if(r==-1) return -1;
        if(abs(l-r)<=1)
            return max(l,r)+1;
        else
            return -1;
    }

    bool isBalanced(TreeNode* root) {
        if(height(root)!=-1)
            return true;
        else
            return false;
    }
};
