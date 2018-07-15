// Given a binary tree, return the postorder traversal of its nodes' values.
//
// Example:
//
//
// Input: [1,null,2,3]
//    1
//     \
//      2
//     /
//    3
//
// Output: [3,2,1]
//
//
// Follow up: Recursive solution is trivial, could you do it iteratively?
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
    vector<int> postorderTraversal(TreeNode* root) {
        stack<TreeNode*> stn;
        stack<int> sb; //0: not visited; 1: Left visited; 2: Right visited
        vector<int> res;
        if(root==NULL) return res;
        stn.push(root);
        sb.push(0);
        while(!stn.empty()) {
            TreeNode* cur=stn.top();
            int cur_status=sb.top();
            if(cur_status==0) {
                sb.pop();
                sb.push(1);
                if(cur->left!=NULL){
                    stn.push(cur->left);
                    sb.push(0);
                }
            }
            else if(cur_status==1) {
                sb.pop();
                sb.push(2);
                if(cur->right!=NULL){
                    stn.push(cur->right);
                    sb.push(0);
                }
            }
            else if(cur_status==2) {
                res.push_back(cur->val);
                sb.pop();
                stn.pop();
            }
        }
        return res;
    }
};
