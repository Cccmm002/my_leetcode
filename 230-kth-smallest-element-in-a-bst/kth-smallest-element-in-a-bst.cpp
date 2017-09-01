// Given a binary search tree, write a function kthSmallest to find the kth smallest element in it.
//
// Note: 
// You may assume k is always valid, 1 &le; k &le; BST's total elements.
//
// Follow up:
// What if the BST is modified (insert/delete operations) often and you need to find the kth smallest frequently? How would you optimize the kthSmallest routine?
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


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
    int counter(TreeNode* root, int k, int *kth, bool* find) {
        if(*find) return 0;
        if(root->left==NULL){
            if(k==1) {
                *find=true;
                *kth=root->val;
                return 0;
            }
            else if(root->right==NULL)
                return 1;
            else
                return counter(root->right,k-1,kth,find)+1;
        }
        int countLeft=0,countRight=0;
        countLeft=counter(root->left,k,kth,find);
        if(k-countLeft==1 && !(*find)){
            *find=true;
            *kth=root->val;
            return countLeft+1;
        }
        if(root->right!=NULL && !(*find))
            countRight=counter(root->right,k-countLeft-1,kth,find);
        return countLeft+countRight+1;
    }

    int kthSmallest(TreeNode* root, int k) {
        int kth=0;
        bool find=false;
        counter(root,k,&kth,&find);
        return kth;
    }
};
