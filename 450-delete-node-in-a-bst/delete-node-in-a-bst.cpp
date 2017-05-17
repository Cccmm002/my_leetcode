// Given a root node reference of a BST and a key, delete the node with the given key in the BST. Return the root node reference (possibly updated) of the BST.
//
// Basically, the deletion can be divided into two stages:
//
// Search for a node to remove.
// If the node is found, delete the node.
//
//
//
// Note: Time complexity should be O(height of tree).
//
// Example:
//
// root = [5,3,6,2,4,null,7]
// key = 3
//
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Given key to delete is 3. So we find the node with value 3 and delete it.
//
// One valid answer is [5,4,6,2,null,null,7], shown in the following BST.
//
//     5
//    / \
//   4   6
//  /     \
// 2       7
//
// Another valid answer is [5,2,6,null,4,null,7].
//
//     5
//    / \
//   2   6
//    \   \
//     4   7


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
    vector<TreeNode**> find(TreeNode* root, int key) {
        vector<TreeNode**> res;
        TreeNode *cur=root;
        while(cur!=NULL) {
            if (cur->val==key)
                break;
            if (cur->val>key) {
                res.push_back(&(cur->left));
                cur=cur->left;
            }
            else {
                res.push_back(&(cur->right));
                cur=cur->right;
            }
        }
        return res;
    }
    
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL) return NULL;
        vector<TreeNode**> path=find(root,key);
        path.insert(path.begin(), &root);
        TreeNode *target=*(path[path.size()-1]);
        if(target==NULL || target->val!=key)
            return root;
        if(target->left==NULL && target->right==NULL) {
            *(path[path.size()-1])=NULL;
        }
        else if(target->left==NULL) {
            *(path[path.size()-1])=target->right;
        }
        else if(target->right==NULL) {
            *(path[path.size()-1])=target->left;
        }
        else {
            TreeNode *r=target->right;
            TreeNode *l=target->left;
            *(path[path.size()-1])=l;
            TreeNode *mover=l->right;
            l->right=r;
            TreeNode *cur=r;
            while(cur->left!=NULL)
                cur=cur->left;
            cur->left=mover;
        }
        return root;
    }
};
