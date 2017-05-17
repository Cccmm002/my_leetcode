// Given a linked list, swap every two adjacent nodes and return its head.
//
//
//
// For example,
// Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//
//
// Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.


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
    ListNode* swapPairs(ListNode* head) {
        ListNode* root = head;
        ListNode* cur = head;
        ListNode** prev = &root;
        while(cur!=NULL) {
            if(cur->next == NULL) break;
            ListNode* a = cur;
            ListNode* b = cur->next;
            ListNode* next = cur->next->next;
            *prev = b;
            b->next = a;
            a->next = next;
            prev = &(a->next);
            cur = next;
        }
        return root;
    }
};
