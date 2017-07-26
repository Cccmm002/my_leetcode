// Given a non-empty binary search tree and a target value, find k values in the BST that are closest to the target.
//
// Note:
//
// Given target value is a floating point.
// You may assume k is always valid, that is: k &le; total nodes.
// You are guaranteed to have only one unique set of k values in the BST that are closest to the target.
//
// Follow up:
// Assume that the BST is balanced, could you solve it in less than O(n) runtime (where n = total nodes)?


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
    TreeNode* suc(TreeNode *root, TreeNode *n) {
        if (n == NULL) return NULL;
        if (n->right != NULL) {
            TreeNode *cur = n->right;
            while (cur->left != NULL)
                cur = cur->left;
            return cur;
        }
        TreeNode *res = NULL;
        TreeNode *cur = root;
        while(cur != NULL) {
            if (n->val < cur->val) {
                res = cur;
                cur = cur->left;
            }
            else if (n->val > cur->val) {
                cur = cur->right;
            }
            else
                break;
        }
        return res;
    }
    
    TreeNode* pre(TreeNode *root, TreeNode *n) {
        if (n == NULL) return NULL;
        if (n->left != NULL) {
            TreeNode *cur = n->left;
            while (cur->right != NULL)
                cur = cur->right;
            return cur;
        }
        TreeNode *res = NULL;
        TreeNode *cur = root;
        while(cur != NULL) {
            if (n->val < cur->val) {
                cur = cur->left;
            }
            else if (n->val > cur->val) {
                res = cur;
                cur = cur->right;
            }
            else
                break;
        }
        return res;
    }
    
    TreeNode* closestValue(TreeNode* root, double target) {
        if (root == NULL) return NULL;
        if (root->left == NULL && root->right == NULL) return root;
        TreeNode *cur = root;
        if (root->left != NULL) {
            TreeNode *next = closestValue(root->left, target);
            double a = abs((double)cur->val - target);
            double b = abs((double)next->val - target);
            if (b < a) cur = next;
        }
        if (root->right != NULL) {
            TreeNode *next = closestValue(root->right, target);
            double a = abs((double)cur->val - target);
            double b = abs((double)next->val - target);
            if (b < a) cur = next;
        }
        return cur;
    }
    
public:
    vector<int> closestKValues(TreeNode* root, double target, int k) {
        vector<int> res;
        TreeNode *closest = closestValue(root, target);
        if (closest == NULL) return res;
        res.push_back(closest->val);
        TreeNode *left = closest;
        TreeNode *right = closest;
        while (k > 1) {
            TreeNode *l = pre(root, left);
            TreeNode *r = suc(root, right);
            if (l == NULL && r == NULL) break;
            if (l == NULL) {
                res.push_back(r->val);
                right = r;
            }
            else if (r == NULL) {
                res.push_back(l->val);
                left = l;
            }
            else {
                double a = abs(target - (double)l->val);
                double b = abs(target - (double)r->val);
                if (a < b) {
                    res.push_back(l->val);
                    left = l;
                }
                else {
                    res.push_back(r->val);
                    right = r;
                }
            }
            k--;
        }
        return res;
    }
};
