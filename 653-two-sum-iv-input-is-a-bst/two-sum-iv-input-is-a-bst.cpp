// Given a Binary Search Tree and a target number, return true if there exist two elements in the BST such that their sum is equal to the given target.
//
// Example 1:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 9
//
// Output: True
//
//
//
//
// Example 2:
//
// Input: 
//     5
//    / \
//   3   6
//  / \   \
// 2   4   7
//
// Target = 28
//
// Output: False


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
    unordered_set<int> us;
    
    bool find(TreeNode* root, int k) {
        if (root == NULL) return false;
        if (us.find(k - root->val) != us.end()) return true;
        us.insert(root->val);
        return find(root->left, k) || find(root->right, k);
    }
    
public:
    bool findTarget(TreeNode* root, int k) {
        return find(root, k);
    }
};
