// Given a binary tree, find its minimum depth.
//
// The minimum depth is the number of nodes along the shortest path from the root node down to the nearest leaf node.


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
    struct nodePack {
        TreeNode *node;
        int level;
        nodePack(TreeNode *n, int l) : node(n), level(l) {}
    };

    int minDepth(TreeNode* root) {
        if(root==NULL) return 0;
        queue<nodePack> q;
        q.push(nodePack(root,0));
        while(!q.empty()){
            nodePack np=q.front();
            q.pop();
            if(np.node->left==NULL && np.node->right==NULL)
                return np.level+1;
            if(np.node->left!=NULL)
                q.push(nodePack(np.node->left,np.level+1));
            if(np.node->right!=NULL)
                q.push(nodePack(np.node->right,np.level+1));
        }
        return -1;
    }
};
