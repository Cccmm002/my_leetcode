// Two elements of a binary search tree (BST) are swapped by mistake.
//
// Recover the tree without changing its structure.
//
//
// Note:
// A solution using O(n) space is pretty straight forward. Could you devise a constant space solution?


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
    TreeNode *mistakeA = NULL;
    TreeNode *A_next = NULL;
    TreeNode *mistakeB = NULL;
    TreeNode *prev = NULL;
    
    void check(TreeNode *cur) {
        if (prev != NULL && prev->val > cur->val) {
            if (mistakeA == NULL) {
                mistakeA = prev;
                A_next = cur;
            }
            else
                mistakeB = cur;
        }
    }
    
    void traversal(TreeNode *root) {
        TreeNode *cur = NULL;
        if (root->left != NULL) {
            traversal(root->left);
        }
        cur = root;
        check(cur);
        prev = cur;
        if (root->right != NULL) {
            traversal(root->right);
        }
    }
    
public:
    void recoverTree(TreeNode* root) {
        traversal(root);
        if(mistakeB != NULL) {
            int temp = mistakeA->val;
            mistakeA->val = mistakeB->val;
            mistakeB->val = temp;
        }
        else {
            int temp = mistakeA->val;
            mistakeA->val = A_next->val;
            A_next->val = temp;
        }
    }
};
