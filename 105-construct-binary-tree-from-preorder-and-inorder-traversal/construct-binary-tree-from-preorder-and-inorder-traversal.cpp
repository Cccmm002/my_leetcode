// Given preorder and inorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.


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
    TreeNode* build(vector<int>::iterator preorder, vector<int>::iterator inorder, int length, unordered_map<int,int>& dic, int offset) {
        if(length==0)
            return NULL;
        TreeNode *res=new TreeNode(*preorder);
        if(length==1)
            return res;
        int root_place=dic[*preorder]-offset;
        res->left=build(preorder+1,inorder,root_place,dic,offset);
        res->right=build(preorder+root_place+1,inorder+root_place+1,length-root_place-1,dic,offset+root_place+1);
        return res;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return build(preorder.begin(),inorder.begin(),preorder.size(),m,0);
    }
};
