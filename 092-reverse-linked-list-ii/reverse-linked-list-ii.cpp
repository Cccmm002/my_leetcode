// Reverse a linked list from position m to n. Do it in-place and in one-pass.
//
//
//
// For example:
// Given 1->2->3->4->5->NULL, m = 2 and n = 4,
//
//
// return 1->4->3->2->5->NULL.
//
//
// Note:
// Given m, n satisfy the following condition:
// 1 ≤ m ≤ n ≤ length of list.


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
    ListNode* reverseBetween(ListNode* head, int m, int n) {
        if (head == NULL) return NULL;
        ListNode *superRoot = new ListNode(-1);
        superRoot->next = head;
        ListNode *prev = superRoot;
        ListNode *start = superRoot->next;
        ListNode *cur = start->next;
        for (int i = 1; i < m; i++) {
            cur = cur->next;
            start = start->next;
            prev = prev->next;
        }
        for (int i = m; i < n; i++) {
            start->next = cur->next;
            cur->next = prev->next;
            prev->next = cur;
            cur = start->next;
        }
        return superRoot->next;
    }
};
