// Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.
//
//
// You should preserve the original relative order of the nodes in each of the two partitions.
//
//
// For example,
// Given 1->4->3->2->5->2 and x = 3,
// return 1->2->2->4->3->5.


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
    ListNode* partition(ListNode* head, int x) {
        if(head == NULL) return NULL;
        ListNode *larger = NULL;
        ListNode *lcur = NULL;
        ListNode *small = NULL;
        ListNode *scur = NULL;
        ListNode *cur = head;
        while(cur != NULL) {
            if (cur->val < x) {
                if (small == NULL) {
                    small = cur;
                    scur = cur;
                }
                else {
                    scur->next = cur;
                    scur = scur->next;
                }
            }
            else {
                if (larger == NULL) {
                    larger = cur;
                    lcur = cur;
                }
                else {
                    lcur->next = cur;
                    lcur = lcur->next;
                }
            }
            ListNode *prev = cur;
            cur = cur->next;
            prev->next = NULL;
        }
        if(small != NULL) {
            scur->next = larger;
            return small;
        }
        else 
            return larger;
    }
};
