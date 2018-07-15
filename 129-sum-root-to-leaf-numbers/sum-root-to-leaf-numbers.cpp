// Given a binary tree containing digits from 0-9 only, each root-to-leaf path could represent a number.
//
// An example is the root-to-leaf path 1->2->3 which represents the number 123.
//
// Find the total sum of all root-to-leaf numbers.
//
// Note: A leaf is a node with no children.
//
// Example:
//
//
// Input: [1,2,3]
//     1
//    / \
//   2   3
// Output: 25
// Explanation:
// The root-to-leaf path 1->2 represents the number 12.
// The root-to-leaf path 1->3 represents the number 13.
// Therefore, sum = 12 + 13 = 25.
//
// Example 2:
//
//
// Input: [4,9,0,5,1]
//     4
//    / \
//   9   0
//  / \
// 5   1
// Output: 1026
// Explanation:
// The root-to-leaf path 4->9->5 represents the number 495.
// The root-to-leaf path 4->9->1 represents the number 491.
// The root-to-leaf path 4->0 represents the number 40.
// Therefore, sum = 495 + 491 + 40 = 1026.
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
