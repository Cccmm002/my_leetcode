// Given a list, rotate the list to the right by k places, where k is non-negative.
//
// For example:
// Given 1->2->3->4->5->NULL and k = 2,
// return 4->5->1->2->3->NULL.


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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == NULL) return NULL;
        ListNode *starter = head;
        ListNode *p1 = head;
        ListNode *p2 = head;
        int len = 0;
        bool ended = false;
        for (int i = 0; i < k; i++) {
            if (!ended) len++;
            p2 = p2->next;
            if (p2 == NULL) {
                p2 = starter;
                ended = true;
                k = k % len;
                i = -1;
            }
        }
        if (p1 == p2) return head;
        while (p2->next != NULL) {
            p2 = p2->next;
            p1 = p1->next;
        }
        ListNode *res = p1->next;
        p1->next = NULL;
        p2->next = starter;
        return res;
    }
};
