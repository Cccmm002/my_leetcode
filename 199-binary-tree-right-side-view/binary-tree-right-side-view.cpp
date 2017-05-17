// Given a binary tree, imagine yourself standing on the right side of it, return the values of the nodes you can see ordered from top to bottom.
//
//
// For example:
// Given the following binary tree,
//
//    1            <---
//  /   \
// 2     3         <---
//  \     \
//   5     4       <---
//
//
//
// You should return [1, 3, 4].
//
//
// Credits:Special thanks to @amrsaqr for adding this problem and creating all test cases.


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
    struct NodePack {
        TreeNode *node;
        int level;
        NodePack(TreeNode *n, int l) : node(n), level(l) {}
    };

    vector<int> rightSideView(TreeNode* root) {
        vector<int> res;
        if(root==NULL) return res;
        queue<NodePack> q;
        q.push(NodePack(root,0));
        int level=0;
        NodePack prev(NULL,0);
        while(!q.empty()){
            NodePack np=q.front();
            q.pop();
            if(np.level!=level){
                level++;
                res.push_back(prev.node->val);
            }
            if(np.node->left!=NULL) q.push(NodePack(np.node->left,np.level+1));
            if(np.node->right!=NULL) q.push(NodePack(np.node->right,np.level+1));
            prev=np;
        }
        res.push_back(prev.node->val);
        return res;
    }
};
