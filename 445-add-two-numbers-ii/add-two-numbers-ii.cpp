// You are given two non-empty linked lists representing two non-negative integers. The most significant digit comes first and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.
//
// You may assume the two numbers do not contain any leading zero, except the number 0 itself.
//
// Follow up:
// What if you cannot modify the input lists? In other words, reversing the lists is not allowed.
//
//
//
// Example:
//
// Input: (7 -> 2 -> 4 -> 3) + (5 -> 6 -> 4)
// Output: 7 -> 8 -> 0 -> 7


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
        stack<int> n1, n2;
        ListNode *p1 = l1;
        ListNode *p2 = l2;
        while (p1 != NULL) {
            n1.push(p1->val);
            p1 = p1->next;
        }
        while (p2 != NULL) {
            n2.push(p2->val);
            p2 = p2->next;
        }
        ListNode *cur = NULL;
        int inc = 0;
        while (!n1.empty() || !n2.empty()) {
            int a, b;
            if (n1.empty())
                a = 0;
            else {
                a = n1.top();
                n1.pop();
            }
            if (n2.empty())
                b = 0;
            else {
                b = n2.top();
                n2.pop();
            }
            int sum = a + b + inc;
            if (sum >= 10) {
                inc = 1;
                sum -= 10;
            }
            else {
                inc = 0;
            }
            ListNode *n = new ListNode(sum);
            n->next = cur;
            cur = n;
        }
        if (inc > 0) {
            ListNode *n = new ListNode(inc);
            n->next = cur;
            return n;
        }
        else {
            return cur;
        }
    }
};
