//
// Given two non-empty binary trees s and t, check whether tree t has exactly the same structure and node values with a subtree of s. A subtree of s is a tree consists of a node in s and all of this node's descendants. The tree s could also be considered as a subtree of itself.
//
//
// Example 1:
//
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
//
// Given tree t:
//
//    4 
//   / \
//  1   2
//
// Return true, because t has the same structure and node values with a subtree of s.
//
//
// Example 2:
//
// Given tree s:
//
//      3
//     / \
//    4   5
//   / \
//  1   2
//     /
//    0
//
// Given tree t:
//
//    4
//   / \
//  1   2
//
// Return false.
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
private:
    bool same(TreeNode *a, TreeNode *b) {
        if (a == NULL && b == NULL) return true;
        if (a == NULL || b == NULL) return false;
        if (a->val != b->val) return false;
        return same(a->left, b->left) && same(a->right, b->right);
    }
    
    bool find(TreeNode *s, TreeNode *t) {
        if (s == NULL) return false;
        if (s->val == t->val) {
            if (same(s, t))
                return true;
        }
        return find(s->left, t) || find(s->right, t);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        if(s == NULL || t == NULL) return false;
        return find(s, t);
    }
};
