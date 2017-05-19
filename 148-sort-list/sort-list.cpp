// Sort a linked list in O(n log n) time using constant space complexity.


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
    ListNode* sortList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *prev = head;
        while (fast->next != NULL && fast->next->next != NULL) {
            fast = fast->next->next;
            prev = slow;
            slow = slow->next;
        }
        if (fast->next != NULL) {
            prev = slow;
            slow = slow->next;
        }
        prev->next = NULL;
        ListNode *a = sortList(head);
        ListNode *b = sortList(slow);
        ListNode *superRoot = new ListNode(-1);
        ListNode *cp = superRoot;
        while (a != NULL || b != NULL) {
            if (b == NULL || (a != NULL && a->val < b->val)) {
                ListNode *anext = a->next;
                a->next = NULL;
                cp->next = a;
                cp = cp->next;
                a = anext;
            }
            else if (a == NULL || (b != NULL && a->val >= b->val)) {
                ListNode *bnext = b->next;
                b->next = NULL;
                cp->next = b;
                cp = cp->next;
                b = bnext;
            }
        }
        ListNode *res = superRoot->next;
        delete superRoot;
        return res;
    }
};
