// Given an integer n, generate all structurally unique BST's (binary search trees) that store values 1 ... n.
//
// Example:
//
//
// Input: 3
// Output:
// [
//   [1,null,3,2],
//   [3,2,null,1],
//   [3,1,null,null,2],
//   [2,1,3],
//   [1,null,2,null,3]
// ]
// Explanation:
// The above output corresponds to the 5 unique BST's shown below:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
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
private:
    TreeNode* cloneTree(TreeNode* tn, int offset) {
        if(tn==NULL) return NULL;
        TreeNode *root = new TreeNode(tn->val + offset);
        root->left = cloneTree(tn->left, offset);
        root->right = cloneTree(tn->right, offset);
        return root;
    }
    
public:
    vector<TreeNode*> generateTrees(int n) {
        vector<vector<TreeNode*>> v;
        vector<TreeNode*> one;
        if(n==0) return one;
        one.push_back(new TreeNode(1));
        if(n==1) return one;
        vector<TreeNode*> nullvec;
        nullvec.push_back(NULL);
        v.push_back(nullvec);
        v.push_back(one);
        for(int i=2;i<=n;i++) {
            vector<TreeNode*> curv;
            for(int k=1;k<=i;k++) {
                TreeNode *tnr = new TreeNode(k);
                for(TreeNode *l : v[k-1]) {
                    tnr->left = l;
                    for(TreeNode *r : v[i-k]) {
                        tnr->right = cloneTree(r, k);
                        curv.push_back(cloneTree(tnr, 0));
                        free(tnr->right);
                        tnr->right = NULL;
                    }
                }
            }
            v.push_back(curv);
        }
        return v[n];
    }
};
