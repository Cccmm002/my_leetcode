// Given a singly linked list L: L0→L1→…→Ln-1→Ln,
// reorder it to: L0→Ln→L1→Ln-1→L2→Ln-2→…
//
// You may not modify the values in the list's nodes, only nodes itself may be changed.
//
// Example 1:
//
//
// Given 1->2->3->4, reorder it to 1->4->2->3.
//
// Example 2:
//
//
// Given 1->2->3->4->5, reorder it to 1->5->2->4->3.
//
//


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
    void reorderList(ListNode* head) {
        if (head == NULL) return;
        ListNode *fast = head;
        ListNode *slow = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            slow = slow->next;
        }
        if (fast == slow) return;
        if (fast->next != NULL) fast = fast->next;
        ListNode *mid = slow;
        //Reverse the second half
        ListNode *prev = mid->next;
        ListNode *cur = mid->next->next;
        if (mid->next->next != NULL) {
            mid->next->next = NULL;
            while (cur->next != NULL) {
                ListNode *next = cur->next;
                cur->next = prev;
                prev = cur;
                cur = next;
            }
            cur->next = prev;
            mid->next = cur;
        }
        //Second pass
        ListNode *l1 = head;
        ListNode *l2 = mid->next;
        while (l2 != NULL && l1 != mid) {
            ListNode *next1 = l1->next;
            ListNode *next2 = l2->next;
            l1->next = l2;
            l2->next = next1;
            mid->next = next2;
            l1 = next1;
            l2 = next2;
        }
    }
};
