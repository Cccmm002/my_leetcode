// Given a binary search tree and a node in it, find the in-order successor of that node in the BST.
//
//
//
// Note: If the given node has no in-order successor in the tree, return null.


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct Node {
    TreeNode *tn;
    bool left;
    Node(TreeNode *t, bool l) : tn(t), left(l) {}
};

class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        if (root == NULL || p == NULL) return NULL;
        if (p->right != NULL) {
            TreeNode *cur = p->right;
            while (cur->left != NULL)
                cur = cur->left;
            return cur;
        }
        stack<Node> s;
        TreeNode *cur = root;
        while (cur != p) {
            if (p->val < cur->val) {
                Node n(cur, true);
                s.push(n);
                cur = cur->left;
            } else {
                Node n(cur, false);
                s.push(n);
                cur = cur->right;
            }
        }
        while (!s.empty()) {
            Node cur = s.top();
            s.pop();
            if (cur.left)
                return cur.tn;
        }
        return NULL;
    }
};
