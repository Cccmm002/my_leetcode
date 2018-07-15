//
// Given a binary tree, find the leftmost value in the last row of the tree. 
//
//
// Example 1:
//
// Input:
//
//     2
//    / \
//   1   3
//
// Output:
// 1
//
//
//
//   Example 2: 
//
// Input:
//
//         1
//        / \
//       2   3
//      /   / \
//     4   5   6
//        /
//       7
//
// Output:
// 7
//
//
//
// Note:
// You may assume the tree (i.e., the given root node) is not NULL.
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
    int findBottomLeftValue(TreeNode* root) {
        queue<NodePack> q;
        q.push(NodePack(root, 0));
        int cur_largest_level = 0;
        int res = root->val;
        while(!q.empty()) {
            NodePack cur = q.front();
            q.pop();
            if(cur.level > cur_largest_level) {
                cur_largest_level = cur.level;
                res = cur.node->val;
            }
            if(cur.node->left != NULL) q.push(NodePack(cur.node->left, cur.level + 1));
            if(cur.node->right != NULL) q.push(NodePack(cur.node->right, cur.level + 1));
        }
        return res;
    }
};
