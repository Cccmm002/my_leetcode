// Given a binary tree where every node has a unique value, and a target key k, find the value of the nearest leaf node to target k in the tree.
//
// Here, nearest to a leaf means the least number of edges travelled on the binary tree to reach any leaf of the tree.  Also, a node is called a leaf if it has no children.
//
// In the following examples, the input tree is represented in flattened form row by row.
// The actual root tree given will be a TreeNode object.
//
// Example 1:
//
// Input:
// root = [1, 3, 2], k = 1
// Diagram of binary tree:
//           1
//          / \
//         3   2
//
// Output: 2 (or 3)
//
// Explanation: Either 2 or 3 is the nearest leaf node to the target of 1.
//
//
// Example 2:
//
// Input:
// root = [1], k = 1
// Output: 1
//
// Explanation: The nearest leaf node is the root node itself.
//
//
//
//
// Example 3:
//
// Input:
// root = [1,2,3,4,null,null,null,5,null,6], k = 2
// Diagram of binary tree:
//              1
//             / \
//            2   3
//           /
//          4
//         /
//        5
//       /
//      6
//
// Output: 3
// Explanation: The leaf node with value 3 (and not the leaf node with value 6) is nearest to the node with value 2.
//
//
//
// Note:
//
// root represents a binary tree with at least 1 node and at most 1000 nodes.
// Every node has a unique node.val in range [1, 1000].
// There exists some node in the given binary tree for which node.val == k.
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
    int res_len = INT_MAX;
    int res = 0;
    
    int find(TreeNode* root, int k, int *toTarget, int *leaf) {
        if (root->val == k) 
            *toTarget = 0;
        if (root->left == NULL && root->right == NULL) {
            *leaf = root->val;
            if (root->val == k) {
                res_len = 0;
                res = root->val;
            }
            return 0;
        }
        int left_tt = -1, right_tt = -1;
        int left_leaf, right_leaf;
        int left = root->left == NULL?INT_MAX:find(root->left, k, &left_tt, &left_leaf);
        int right = root->right == NULL?INT_MAX:find(root->right, k, &right_tt, &right_leaf);
        //cout<<root->val<<" "<<left_tt<<" "<<right_tt<<endl;
        if (root->val != k) {
            if (left_tt == -1 && right_tt == -1)
                *toTarget = -1;
            else if (left_tt >= 0)
                *toTarget = left_tt + 1;
            else
                *toTarget = right_tt + 1;
        }
        int ret;
        if (left <= right) {
            ret = left + 1;
            *leaf = left_leaf;
        }
        else {
            ret = right + 1;
            *leaf = right_leaf;
        }
        if (root->val == k) {
            res_len = ret;
            res = *leaf;
            //cout<<res_len<<" "<<res<<endl;
        }
        else {
            int tempt;
            int lll;
            if (*toTarget == -1) return ret;
            if (left_tt >= 0) {
                tempt = root->right == NULL?INT_MAX:(left_tt + right + 2);
                lll = right_leaf;
            }
            else {
                tempt = root->left == NULL?INT_MAX:(right_tt + left + 2);
                lll = left_leaf;
            }
            //cout<<root->val<<" "<<left_tt<<" "<<right_tt<<" "<<left<<" "<<right<<" "<<tempt<<endl;
            if (tempt < res_len) {
                res_len = tempt;
                res = lll;
            }
        }
        return ret;
    }
    
public:
    int findClosestLeaf(TreeNode* root, int k) {
        int tt, tl;
        find(root, k, &tt, &tl);
        return res;
    }
};
