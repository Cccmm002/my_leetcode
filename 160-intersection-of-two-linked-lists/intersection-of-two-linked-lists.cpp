// Write a program to find the node at which the intersection of two singly linked lists begins.
//
// For example, the following two linked lists: 
//
// A:          a1 → a2
//                    ↘
//                      c1 → c2 → c3
//                    ↗            
// B:     b1 → b2 → b3
//
// begin to intersect at node c1.
//
// Notes:
//
// If the two linked lists have no intersection at all, return null.
// The linked lists must retain their original structure after the function returns. 
// You may assume there are no cycles anywhere in the entire linked structure.
// Your code should preferably run in O(n) time and use only O(1) memory.
//
//
//
// Credits:Special thanks to @stellari for adding this problem and creating all test cases.


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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        if (headA == NULL || headB == NULL) return NULL;
        int la = 0;
        int lb = 0;
        ListNode *pa = headA;
        ListNode *pb = headB;
        while (pa != NULL) {
            la++;
            pa = pa->next;
        }
        while (pb != NULL) {
            lb++;
            pb = pb->next;
        }
        pa = headA;
        pb = headB;
        if (la > lb) {
            for (int i = 0; i < la - lb; i++) pa = pa->next;
        }
        else if (la < lb) {
            for (int i = 0; i < lb - la; i++) pb = pb->next;
        }
        while (pa != pb) {
            pa = pa->next;
            pb = pb->next;
            if (pa == NULL || pb == NULL) break;
        }
        if (pa == pb) return pa;
        else return NULL;
    }
};
