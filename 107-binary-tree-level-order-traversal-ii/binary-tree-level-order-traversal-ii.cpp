// Given a binary tree, return the bottom-up level order traversal of its nodes' values. (ie, from left to right, level by level from leaf to root).
//
//
// For example:
// Given binary tree [3,9,20,null,null,15,7],
//
//     3
//    / \
//   9  20
//     /  \
//    15   7
//
//
//
// return its bottom-up level order traversal as:
//
// [
//   [15,7],
//   [9,20],
//   [3]
// ]


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

vector<vector<int>> levelOrderBottom(TreeNode* root) {
    std::queue<NodePack> q;
    NodePack np(root,0);
    q.push(np);
    int level=0;
    vector<TreeNode*> v;
    v.clear();
    vector<vector<int>> res;
    while(q.size()!=0){
        NodePack cur=q.front();
        if(level!=cur.level){
            vector<int> vi;
            for(int i=0;i<v.size();i++) {
                if(v[i]!=NULL)
                    vi.push_back(v[i]->val);
            }
            res.push_back(vi);
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

    vector<vector<int>> r;
    for(int i=res.size()-1;i>=0;i--)
        r.push_back(res[i]);
    return r;
}
};
