// Given a binary tree and a sum, find all root-to-leaf paths where each path's sum equals the given sum.
//
// Note: A leaf is a node with no children.
//
// Example:
//
// Given the below binary tree and sum = 22,
//
//
//       5
//      / \
//     4   8
//    /   / \
//   11  13  4
//  /  \    / \
// 7    2  5   1
//
//
// Return:
//
//
// [
//    [5,4,11,2],
//    [5,8,4,5]
// ]
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
public:
    vector<vector<int>> _pathSum(TreeNode* root, int sum) {
        vector<vector<int>> res;
        res.clear();
        if(root==NULL) return res;
        if(root->val==sum && root->left==NULL && root->right==NULL){
            vector<int> v={sum};
            res.push_back(v);
            return res;
        }
        if(root->left!=NULL){
            vector<vector<int>> ps=_pathSum(root->left,sum-root->val);
            for(auto vi : ps){
                vi.push_back(root->val);
                res.push_back(vi);
            }
        }
        if(root->right!=NULL){
            vector<vector<int>> ps=_pathSum(root->right,sum-root->val);
            for(auto vi : ps){
                vi.push_back(root->val);
                res.push_back(vi);
            }
        }
        return res;
    }
    
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        vector<vector<int>> r=_pathSum(root, sum);
        vector<vector<int>> res;
        res.clear();
        for(auto vi:r){
            vector<int> resv;
            for(int i=vi.size()-1;i>=0;i--)
                resv.push_back(vi[i]);
            res.push_back(resv);
        }
        return res;
    }
};
