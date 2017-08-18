// Given a binary tree, return the values of its boundary in anti-clockwise direction starting from root.
// Boundary includes left boundary, leaves, and right boundary in order without duplicate nodes. 
//
// Left boundary is defined as the path from root to the left-most node. Right boundary is defined as the path from root to the right-most node. If the root doesn't have left subtree or right subtree, then the root itself is left boundary or right boundary. Note this definition only applies to the input binary tree, and not applies to any subtrees.
//
// The left-most node is defined as a leaf node you could reach when you always firstly travel to the left subtree if exists. If not, travel to the right subtree. Repeat until you reach a leaf node.
//
// The right-most node is also defined by the same way with left and right exchanged.
//
//
// Example 1
//
// Input:
//   1
//    \
//     2
//    / \
//   3   4
//
// Ouput:
// [1, 3, 4, 2]
//
// Explanation:
// The root doesn't have left subtree, so the root itself is left boundary.
// The leaves are node 3 and 4.
// The right boundary are node 1,2,4. Note the anti-clockwise direction means you should output reversed right boundary.
// So order them in anti-clockwise without duplicates and we have [1,3,4,2].
//
//
//
//
// Example 2
//
// Input:
//     ____1_____
//    /          \
//   2            3
//  / \          / 
// 4   5        6   
//    / \      / \
//   7   8    9  10  
//
// Ouput:
// [1,2,4,7,8,9,10,6,3]
//
// Explanation:
// The left boundary are node 1,2,4. (4 is the left-most node according to definition)
// The leaves are node 4,7,8,9,10.
// The right boundary are node 1,3,6,10. (10 is the right-most node).
// So order them in anti-clockwise without duplicate nodes we have [1,2,4,7,8,9,10,6,3].


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
    vector<TreeNode*> findLeft(TreeNode *root) {
        vector<TreeNode*> res;
        TreeNode *cur = root;
        res.push_back(root);
        if (root->left == NULL) return res;
        while (cur->left != NULL || cur->right != NULL) {
            if (cur->left == NULL) {
                res.push_back(cur->right);
                cur = cur->right;
            }
            else {
                res.push_back(cur->left);
                cur = cur->left;
            }
        }
        return res;
    }
    
    vector<TreeNode*> findRight(TreeNode *root) {
        vector<TreeNode*> res;
        TreeNode *cur = root;
        res.push_back(root);
        if (root->right == NULL) return res;
        while (cur->left != NULL || cur->right != NULL) {
            if (cur->right == NULL) {
                res.push_back(cur->left);
                cur = cur->left;
            }
            else {
                res.push_back(cur->right);
                cur = cur->right;
            }
        }
        return res;
    }
    
    void findLeaves(TreeNode *root, vector<TreeNode*> &res) {
        if (root == NULL) return;
        if (root->left == NULL && root->right == NULL) {
            res.push_back(root);
            return;
        }
        if (root->left != NULL) findLeaves(root->left, res);
        if (root->right != NULL) findLeaves(root->right, res);
    }
    
public:
    vector<int> boundaryOfBinaryTree(TreeNode* root) {
        vector<int> res;
        if (root == NULL) return res;
        unordered_set<TreeNode*> s;
        vector<TreeNode*> left = findLeft(root);
        vector<TreeNode*> right = findRight(root);
        vector<TreeNode*> leaves;
        findLeaves(root, leaves);
        reverse(right.begin(), right.end());
        for (int i = 0; i < left.size(); i++) {
            if (s.find(left[i]) != s.end()) continue;
            s.insert(left[i]);
            res.push_back(left[i]->val);
        }
        for (int i = 0; i < leaves.size(); i++) {
            if (s.find(leaves[i]) != s.end()) continue;
            s.insert(leaves[i]);
            res.push_back(leaves[i]->val);
        }
        for (int i = 0; i < right.size(); i++) {
            if (s.find(right[i]) != s.end()) continue;
            s.insert(right[i]);
            res.push_back(right[i]->val);
        }
        return res;
    }
};
