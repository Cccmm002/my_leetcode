//
// Given a binary tree with n nodes, your task is to check if it's possible to partition the tree to two trees which have the equal sum of values after removing exactly one edge on the original tree.
//
//
// Example 1:
//
// Input:     
//     5
//    / \
//   10 10
//     /  \
//    2   3
//
// Output: True
// Explanation: 
//     5
//    / 
//   10
//
// Sum: 15
//
//    10
//   /  \
//  2    3
//
// Sum: 15
//
//
//
//
// Example 2:
//
// Input:     
//     1
//    / \
//   2  10
//     /  \
//    2   20
//
// Output: False
// Explanation: You can't split the tree into two trees with equal sum after removing exactly one edge on the tree.
//
//
//
// Note:
//
// The range of tree node value is in the range of [-100000, 100000].
// 1 <= n <= 10000
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
    int getSum(TreeNode* root, unordered_set<int> &record) {
        int sum = root->val;
        if (root->left != NULL) 
            sum += getSum(root->left, record);
        if (root->right != NULL) 
            sum += getSum(root->right, record);
        record.insert(sum);
        return sum;
    }
    
public:
    bool checkEqualTree(TreeNode* root) {
        if (root == NULL) return false;
        if (root->left == NULL && root->right == NULL) return false;
        unordered_set<int> record;
        int total = getSum(root, record);
        if ((total & 1) == 1) return false;
        return record.find(total/2) != record.end();
    }
};
