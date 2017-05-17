// Given a linked list, return the node where the cycle begins. If there is no cycle, return null.
//
//
//
// Note: Do not modify the linked list.
//
//
// Follow up:
// Can you solve it without using extra space?


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
    ListNode *detectCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) return NULL;
        ListNode *faster = head->next->next;
        ListNode *slower = head->next;
        ListNode *third = head;
        while (faster != slower) {
            if (slower == NULL || faster == NULL) return NULL;
            if (faster->next == NULL) return NULL;
            slower = slower->next;
            faster = faster->next->next;
        }
        while (slower != third) {
            slower = slower->next;
            third = third->next;
        }
        return third;
    }
};
