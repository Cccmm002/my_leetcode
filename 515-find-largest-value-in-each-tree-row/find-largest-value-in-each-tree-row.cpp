// You need to find the largest value in each row of a binary tree.
//
// Example:
//
// Input: 
//
//           1
//          / \
//         3   2
//        / \   \  
//       5   3   9 
//
// Output: [1, 3, 9]
//
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
    struct NodePack {
        TreeNode *node;
        int level;
        
        NodePack(TreeNode *n, int l) : node(n), level(l) {}
    };
public:
    vector<int> largestValues(TreeNode* root) {
        vector<int> res;
        if(root == NULL) return res;
        
        queue<NodePack> q;
        q.push(NodePack(root, 0));
        
        int cur_max = 0 - INT_MAX - 1;
        int cur_level = 0;
        while(!q.empty()) {
            NodePack np = q.front();
            q.pop();
            if(cur_level != np.level) {
                res.push_back(cur_max);
                cur_max = 0 - INT_MAX - 1;
                cur_level = np.level;
            }
            cur_max = cur_max > np.node->val ? cur_max : np.node->val;
            if(np.node->left != NULL) q.push(NodePack(np.node->left, np.level + 1));
            if(np.node->right != NULL) q.push(NodePack(np.node->right, np.level + 1));
        }
        res.push_back(cur_max);
        return res;
    }
};
