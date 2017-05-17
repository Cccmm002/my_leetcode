// Given a binary tree, find its maximum depth.
//
// The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.


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

    int maxDepth(TreeNode* root) {
        if(root==NULL) return 0;
        int maxLevel=0;
        queue<nodePack> q;
        q.push(nodePack(root,0));
        while(!q.empty()){
            nodePack np=q.front();
            q.pop();
            if(np.node->left==NULL && np.node->right==NULL){
                if(maxLevel<np.level+1)
                    maxLevel=np.level+1;
            }
            if(np.node->left!=NULL)
                q.push(nodePack(np.node->left,np.level+1));
            if(np.node->right!=NULL)
                q.push(nodePack(np.node->right,np.level+1));
        }
        return maxLevel;
    }
};