// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// For example,
//
//     1
//    / \
//   2   3
//
//
//
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
//
//
// Return the sum = 12 + 13 = 25.


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
    void getNum(TreeNode* root,vector<int>& numbers,stack<int>& stacks){
        if(root==NULL) return;
        if(root->left==NULL && root->right==NULL){
            stack<int> cur=stacks;
            cur.push(root->val);
            int digits=1;
            int num=0;
            while(!cur.empty()){
                int d=cur.top();
                cur.pop();
                num+=d*digits;
                digits=digits*10;
            }
            numbers.push_back(num);
        }
        else{
            stacks.push(root->val);
            getNum(root->left,numbers,stacks);
            getNum(root->right,numbers,stacks);
            stacks.pop();
        }
    }

    int sumNumbers(TreeNode* root) {
        if(root==NULL) return 0;
        vector<int> numbers;
        stack<int> stacks;
        getNum(root,numbers,stacks);
        int sum=0;
        for(int i:numbers)
            sum+=i;
        return sum;
    }
};
