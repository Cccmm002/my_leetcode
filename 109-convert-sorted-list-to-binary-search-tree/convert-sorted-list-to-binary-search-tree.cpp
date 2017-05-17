// Given a singly linked list where elements are sorted in ascending order, convert it to a height balanced BST.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        int length=nums.size();
        if(length==0) return NULL;
        int middle=length/2;
        TreeNode* root=new TreeNode(nums[middle]);
        vector<int> l(nums.begin(),nums.begin()+middle);
        vector<int> r(nums.begin()+middle+1,nums.end());
        root->left=sortedArrayToBST(l);
        root->right=sortedArrayToBST(r);
        return root;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        vector<int> v;
        while(head!=NULL){
            v.push_back(head->val);
            head=head->next;
        }
        sort(v.begin(),v.end());
        return sortedArrayToBST(v);
    }
};