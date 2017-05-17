// Given a binary tree, flatten it to a linked list in-place.
//
//
//
// For example,
// Given
//
//          1
//         / \
//        2   5
//       / \   \
//      3   4   6
//
//
//
// The flattened tree should look like:
//
//    1
//     \
//      2
//       \
//        3
//         \
//          4
//           \
//            5
//             \
//              6
//
//
// click to show hints.
//
// Hints:
// If you notice carefully in the flattened tree, each node's right child points to the next node of a pre-order traversal.


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
    TreeNode* flat(TreeNode* root) {
        if(root==NULL) return NULL;
        if(root->left==NULL && root->right==NULL)
            return root;
        if(root->left==NULL)
            return flat(root->right);
        if(root->right==NULL){
            root->right=root->left;
            root->left=NULL;
            return flat(root->right);
        }
        TreeNode* leftEnding=flat(root->left);
        TreeNode* rightEnding=flat(root->right);
        leftEnding->right=root->right;
        root->right=root->left;
        root->left=NULL;
        return rightEnding;
    }

    void flatten(TreeNode* root) {
        TreeNode* res=flat(root);
    }
};
