// We are given a binary tree (with root node root), a target node, and an integer value K.
//
// Return a list of the values of all nodes that have a distance K from the target node.  The answer can be returned in any order.
//
//  
//
//
//
//
//
// Example 1:
//
//
// Input: root = [3,5,1,6,2,0,8,null,null,7,4], target = 5, K = 2
//
// Output: [7,4,1]
//
// Explanation: 
// The nodes that are a distance 2 from the target node (with value 5)
// have values 7, 4, and 1.
//
//
//
// Note that the inputs "root" and "target" are actually TreeNodes.
// The descriptions of the inputs above are just serializations of these objects.
//
//
//  
//
// Note:
//
//
// 	The given tree is non-empty.
// 	Each node in the tree has unique values 0 <= node.val <= 500.
// 	The target node is a node in the tree.
// 	0 <= K <= 1000.
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
    vector<int> results;
    
    void simple_dfs(TreeNode* root, int level) {
        if (root == NULL)
            return;
        if (level == 0)
            results.push_back(root->val);
        simple_dfs(root->left, level - 1);
        simple_dfs(root->right, level - 1);
    }
    
    int dfs(TreeNode* root, TreeNode* target, int K) {
        if (root == NULL)
            return -1;
        if (target == root) {
            simple_dfs(root, K);
            return 1;
        }
        int left = dfs(root->left, target, K);
        int right = dfs(root->right, target, K);
        if (left == K || right == K)
            results.push_back(root->val);
        if (left >= 0) {
            simple_dfs(root->right, K - left - 1);
            return left + 1;
        }
        else if (right >= 0) {
            simple_dfs(root->left, K - right - 1);
            return right + 1;
        }
        return -1;
    }
    
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        if (root != NULL) {
            dfs(root, target, K);
        }
        return results;
    }
};
