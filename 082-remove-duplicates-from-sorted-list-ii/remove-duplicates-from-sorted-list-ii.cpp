// Given a sorted linked list, delete all nodes that have duplicate numbers, leaving only distinct numbers from the original list.
//
//
// For example,
// Given 1->2->3->3->4->4->5, return 1->2->5.
// Given 1->1->1->2->3, return 2->3.


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
        ListNode *superRoot = new ListNode(-1);
        superRoot->next = head;
        ListNode *starter = superRoot;
        ListNode *prev = head;
        ListNode *cur = head->next;
        int count = 1;
        int curNum = head->val;
        while (cur != NULL) {
            if (curNum != cur->val) {
                if (count == 1) {
                    starter->next = prev;
                    starter = prev;
                }
                curNum = cur->val;
                count = 1;
            }
            else {
                count++;
            }
            prev = cur;
            cur = cur->next;
        }
        if (count == 1) {
            starter->next = prev;
        }
        else {
            starter->next = NULL;
        }
        return superRoot->next;
    }
};
