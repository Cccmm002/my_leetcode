// Merge two sorted linked lists and return it as a new list. The new list should be made by splicing together the nodes of the first two lists.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode *root=NULL;
        ListNode *current=NULL;
        
        while(l1!=NULL || l2!=NULL) {
            ListNode *next;
            if(l1==NULL) {
                next=l2;
                l2=l2->next;
            }
            else if(l2==NULL) {
                next=l1;
                l1=l1->next;
            }
            else if(l1->val>l2->val) {
                next=l2;
                l2=l2->next;
            }
            else {
                next=l1;
                l1=l1->next;
            }
            if(root==NULL) {
                root=next;
                current=next;
            }
            else {
                current->next=next;
                current=current->next;
            }
        }
        return root;
    }
};