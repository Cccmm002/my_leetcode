// Given a sorted linked list, delete all duplicates such that each element appear only once.
//
//
// For example,
// Given 1->1->2, return 1->2.
// Given 1->1->2->3->3, return 1->2->3.


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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *prev = head;
        ListNode *cur = head->next;
        while (cur != NULL) {
            if (cur->val != prev->val) {
                prev->next = cur;
                prev = cur;
                cur = cur->next;
            }
            else {
                cur = cur->next;
            }
        }
        prev->next = NULL;
        return head;
    }
};

