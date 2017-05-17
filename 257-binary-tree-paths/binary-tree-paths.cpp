// Given a binary tree, return all root-to-leaf paths.
//
//
// For example, given the following binary tree:
//
//
//
//    1
//  /   \
// 2     3
//  \
//   5
//
//
//
// All root-to-leaf paths are:
// ["1->2->5", "1->3"]
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


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
    vector<vector<int>> findPath(TreeNode* root) {
        vector<vector<int>> res;
        res.clear();
        if(root==NULL) return res;
        if(root->left==NULL && root->right==NULL){
            vector<int> vi={root->val};
            res.push_back(vi);
            return res;
        }
        if(root->left!=NULL){
            vector<vector<int>> v=findPath(root->left);
            for(auto vi:v){
                vi.push_back(root->val);
                res.push_back(vi);
            }
        }
        if(root->right!=NULL){
            vector<vector<int>> v=findPath(root->right);
            for(auto vi:v){
                vi.push_back(root->val);
                res.push_back(vi);
            }
        }
        return res;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<vector<int>> v=findPath(root);
        vector<string> res;
        for(auto vi:v){
            string s="";
            for(int i=vi.size()-1;i>=0;i--){
                s+=to_string(vi[i]);
                if(i!=0) s+="->";
            }
            res.push_back(s);
        }
        return res;
    }
};
