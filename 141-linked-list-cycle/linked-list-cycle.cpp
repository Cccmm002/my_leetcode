// Given a linked list, determine if it has a cycle in it.
//
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
    bool hasCycle(ListNode *head) {
        ListNode *walk = head;
        ListNode *run = head;
        while(walk != NULL && run != NULL) {
            run = run->next;
            if(walk->next==NULL) break;
            walk = walk->next->next;
            if(walk==run && walk != NULL) return true;
        }
        return false;
    }
};
