// You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
//
// Example
//
// Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 0 -> 8
// Explanation: 342 + 465 = 807.
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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *res_top=new ListNode(0);
    ListNode *cur=res_top;
    int inc=0;
    int a,b;
    while(l1!=NULL || l2!=NULL) {
        if (l1 != NULL) {
            a = l1->val;
            l1=l1->next;
        }
        else
            a = 0;
        if (l2 != NULL) {
            b = l2->val;
            l2=l2->next;
        }
        else
            b = 0;

        int sum = a + b + inc;
        if (sum >= 10) {
            inc = 1;
            sum -= 10;
        }
        else
            inc=0;
        cur->next=new ListNode(sum);
        cur=cur->next;
    }
    if(inc>0)
        cur->next=new ListNode(inc);
    return res_top->next;
    }
};
