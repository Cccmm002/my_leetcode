// Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//
//
// k is a positive integer and is less than or equal to the length of the linked list. If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
// You may not alter the values in the nodes, only nodes itself may be changed.
//
// Only constant memory is allowed.
//
//
// For example,
// Given this linked list: 1->2->3->4->5
//
//
//
// For k = 2, you should return: 2->1->4->3->5
//
//
//
// For k = 3, you should return: 3->2->1->4->5


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
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL) return NULL;
        if (k == 1) return head;
        ListNode *superRoot = new ListNode(-1);
        superRoot->next = head;
        ListNode *prev = superRoot;
        ListNode *start = head;
        ListNode *cur = head->next;
        ListNode *faster = head;
        int segment = 0;
        while (faster != NULL) {
            segment++;
            ListNode *flag = faster->next;
            if (segment == k) {
                while (cur != flag) {
                    start->next = cur->next;
                    cur->next = prev->next;
                    prev->next = cur;
                    cur = start->next;
                }
                if (flag == NULL) break;
                segment = 0;
                prev = start;
                start = prev->next;
                cur = start->next;
            }
            faster = flag;
        }
        ListNode *res = superRoot->next;
        delete superRoot;
        return res;
    }
};
