// Given inorder and postorder traversal of a tree, construct the binary tree.
//
// Note:
// You may assume that duplicates do not exist in the tree.
//
// For example, given
//
//
// inorder = [9,3,15,20,7]
// postorder = [9,15,7,20,3]
//
// Return the following binary tree:
//
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
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
    TreeNode* build(vector<int>::iterator postorder, vector<int>::iterator inorder, int length, unordered_map<int,int>& dic, int offset) {
        if(length==0)
            return NULL;
        TreeNode *res=new TreeNode(*(postorder-1));
        if(length==1)
            return res;
        int root_place=dic[*(postorder-1)]-offset;
        res->left=build(postorder-length+root_place,inorder,root_place,dic,offset);
        res->right=build(postorder-1,inorder+root_place+1,length-root_place-1,dic,offset+root_place+1);
        return res;
    }
    
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> m;
        for(int i=0;i<inorder.size();i++)
            m[inorder[i]]=i;
        return build(postorder.end(),inorder.begin(),inorder.size(),m,0);
    }
};
