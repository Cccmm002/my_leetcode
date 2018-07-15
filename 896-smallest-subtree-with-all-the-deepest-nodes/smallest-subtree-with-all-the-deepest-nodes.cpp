// Given a binary tree rooted at root, the depth of each node is the shortest distance to the root.
//
// A node is deepest if it has the largest depth possible among any node in the entire tree.
//
// The subtree of a node is that node, plus the set of all descendants of that node.
//
// Return the node with the largest depth such that it contains all the deepest nodes in its subtree.
//
//  
//
// Example 1:
//
//
// Input: [3,5,1,6,2,0,8,null,null,7,4]
// Output: [2,7,4]
// Explanation:
//
//
//
// We return the node with value 2, colored in yellow in the diagram.
// The nodes colored in blue are the deepest nodes of the tree.
// The input "[3, 5, 1, 6, 2, 0, 8, null, null, 7, 4]" is a serialization of the given tree.
// The output "[2, 7, 4]" is a serialization of the subtree rooted at the node with value 2.
// Both the input and output have TreeNode type.
//
//
//  
//
// Note:
//
//
// 	The number of nodes in the tree will be between 1 and 500.
// 	The values of each node are unique.
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
    TreeNode* LCA(TreeNode *root, unordered_set<TreeNode*> &bottoms) {
        if (root == NULL)
            return NULL;
        if (bottoms.find(root) != bottoms.end())
            return root;        // root is one of deepest nodes
        TreeNode *left = LCA(root->left, bottoms);
        TreeNode *right = LCA(root->right, bottoms);
        if (left == NULL)
            return right;
        if (right == NULL)
            return left;
        return root;
    }
        
public:
    TreeNode* subtreeWithAllDeepest(TreeNode* root) {
        if (root == NULL) 
            return NULL;
        unordered_set<TreeNode*> bottoms;   // Used to store current deepest nodes
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {   // BFS to find the deepest level, store in 'bottoms'
            int count = q.size();
            if (count > 0)
                bottoms.clear();  // Previous nodes in 'bottoms' are not deepest
            for (int i = 0; i < count; i++) {
                TreeNode *current = q.front();
                q.pop();
                bottoms.insert(current);
                if (current->left != NULL)
                    q.push(current->left);
                if (current->right != NULL)
                    q.push(current->right);
            }
        }
        return LCA(root, bottoms);
    }
};
