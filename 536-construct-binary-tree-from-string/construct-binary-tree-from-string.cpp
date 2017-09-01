// You need to construct a binary tree from a string consisting of parenthesis and integers. 
//
// The whole input represents a binary tree. It contains an integer followed by zero, one or two pairs of parenthesis. The integer represents the root's value and a pair of parenthesis contains a child binary tree with the same structure. 
//
// You always start to construct the left child node of the parent first if it exists.
//
// Example:
//
// Input: "4(2(3)(1))(6(5))"
// Output: return the tree root node representing the following tree:
//
//        4
//      /   \
//     2     6
//    / \   / 
//   3   1 5   
//
//
//
// Note:
//
// There will only be '(',  ')',  '-' and  '0' ~ '9' in the input string.
// An empty tree is represented by "" instead of "()".


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
    TreeNode* str2tree(string s) {
        if (s == "") return nullptr;
        int n = s.size();
        int pointer = 0;
        while (pointer < n) {
            if (pointer < n && (s[pointer] != '(' && s[pointer] != ')'))
                pointer++;
            else
                break;
        }
        int val = stoi(s.substr(0, pointer));
        TreeNode *node = new TreeNode(val);
        int pl = pointer + 1;
        int para = 0;
        while (pl < n) {
            if (s[pl] == '(') para++;
            if (s[pl] == ')') {
                para--;
                if (para < 0) break;
            }
            pl++;
        }
        if (pl - pointer - 1 > 0) {
            string next = s.substr(pointer + 1, pl - pointer - 1);
            node->left = str2tree(next);
        }
        int pr = pl + 2;
        para = 0;
        while (pr < n) {
            if (s[pr] == '(') para++;
            if (s[pr] == ')') {
                para--;
                if (para < 0) break;
            }
            pr++;
        }
        if (pr - pl - 2 > 0) {
            string next = s.substr(pl + 2, pr - pl - 2);
            node->right = str2tree(next);
        }
        return node;
    }
};
