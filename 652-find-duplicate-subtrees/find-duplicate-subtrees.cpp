// Given a binary tree, return all duplicate subtrees. For each kind of duplicate subtrees, you only need to return the root node of any one of them.
//
// Two trees are duplicate if they have the same structure with same node values.
//
// Example 1: 
//
//
//         1
//        / \
//       2   3
//      /   / \
//     4   2   4
//        /
//       4
//
//
// The following are two duplicate subtrees:
//
//
//       2
//      /
//     4
//
//
// and
//
//
//     4
//
// Therefore, you need to return above trees' root in the form of a list.


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
    unordered_map<int, TreeNode*> m;
    unordered_set<TreeNode*> res_set;
    
    int getString(TreeNode* root) {
        if (root == NULL) return hash<string>{}("#");
        int left = getString(root->left);
        int right = getString(root->right);
        int res = hash<string>{}(to_string(left) + to_string(root->val) + to_string(right));
        if (m.find(res) != m.end()) {
            res_set.insert(m[res]);
        }
        else {
            m[res] = root;
        }
        return res;
    }

public:
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        getString(root);
        vector<TreeNode*> res;
        auto it = res_set.begin();
        while(it != res_set.end()) {
            res.push_back(*it);
            it++;
        }
        return res;
    }
};
