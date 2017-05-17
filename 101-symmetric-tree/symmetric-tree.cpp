// Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//
// For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//     1
//    / \
//   2   2
//  / \ / \
// 3  4 4  3
//
//
//
// But the following [1,2,2,null,3,null,3]  is not:
//
//     1
//    / \
//   2   2
//    \   \
//    3    3
//
//
//
//
// Note:
// Bonus points if you could solve it both recursively and iteratively.


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
public:
struct NodePack {
    TreeNode *node;
    int level;
    NodePack(TreeNode *n, int l) : node(n), level(l) {}
};

bool isSymmetric(TreeNode* root) {
    std::queue<NodePack> q;
    NodePack np(root,0);
    q.push(np);
    int level=0;
    vector<TreeNode*> v;
    v.clear();
    while(q.size()!=0){
        NodePack cur=q.front();
        if(level!=cur.level){
            auto begin=v.begin();
            auto end=v.end()-1;
            while(begin<end){
                TreeNode *b=*begin;
                TreeNode *e=*end;
                if(!(b==NULL && e==NULL)) {
                    if (b == NULL || e == NULL) return false;
                    if (b->val != e->val) return false;
                }
                begin++;
                end--;
            }
            v.clear();
            level++;
        }
        if(cur.node!=NULL) {
            NodePack left(cur.node->left, cur.level + 1);
            q.push(left);
            NodePack right(cur.node->right, cur.level + 1);
            q.push(right);
        }
        v.push_back(cur.node);
        q.pop();
    }
    return true;
}
};
