//
// The thief has found himself a new place for his thievery again. There is only one entrance to this area, called the "root." Besides the root, each house has one and only one parent house. After a tour, the smart thief realized that "all houses in this place forms a binary tree". It will automatically contact the police if two directly-linked houses were broken into on the same night.
//
//
//
// Determine the maximum amount of money the thief can rob tonight without alerting the police.
//
//
// Example 1:
//
//      3
//     / \
//    2   3
//     \   \ 
//      3   1
//
// Maximum amount of money the thief can rob = 3 + 3 + 1 = 7.
//
//
// Example 2:
//
//      3
//     / \
//    4   5
//   / \   \ 
//  1   3   1
//
// Maximum amount of money the thief can rob = 4 + 5 = 9.
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


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
    int _rob(TreeNode* root, unordered_map<TreeNode*, int> &m) {
        if(root==NULL) return 0;
        auto it=m.find(root);
        if(it!=m.end()) return it->second;
        int nope=_rob(root->left,m)+_rob(root->right,m);
        int yep=root->val+((root->left==NULL)?0:(_rob(root->left->left,m)+_rob(root->left->right,m)))+
            ((root->right==NULL)?0:(_rob(root->right->left,m)+_rob(root->right->right,m)));
        int res=(yep>nope)?yep:nope;
        m[root]=res;
        return res;
    }
    
    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> m;
        return _rob(root,m);
    }
};
