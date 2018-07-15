// Given a non-negative integer represented as non-empty a singly linked list of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.
//
// Example:
//
// Input:
// 1->2->3
//
// Output:
// 1->2->4
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
    ListNode* plusOne(ListNode* head) {
        ListNode *super = new ListNode(0);
        super->next = head;
        ListNode *prev = super;
        ListNode *cur = head;
        while (cur->next != NULL) {
            cur = cur->next;
            prev = prev->next;
        }
        if (cur->val < 9) {
            cur->val += 1;
            ListNode *res = head;
            while (res->val == 0) res = res->next;
            return res;
        }
        else {
            cur->val = 0;
            prev->next = NULL;
            ListNode *res = plusOne(super);
            ListNode *node = res;
            while (node->next != NULL) node = node->next;
            node->next = cur;
            while (res->val == 0) res = res->next;
            return res;
        }
    }
};
