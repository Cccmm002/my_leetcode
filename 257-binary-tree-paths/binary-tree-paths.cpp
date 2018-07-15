// Given a binary tree, return all root-to-leaf paths.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input:
//
//    1
//  /   \
// 2     3
//  \
//   5
//
// Output: ["1->2->5", "1->3"]
//
// Explanation: All root-to-leaf paths are: 1->2->5, 1->3
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
