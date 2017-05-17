// Remove all elements from a linked list of integers that have value val.
//
// Example
// Given: 1 --> 2 --> 6 --> 3 --> 4 --> 5 --> 6,  val = 6
// Return: 1 --> 2 --> 3 --> 4 --> 5
//
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


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
    ListNode* removeElements(ListNode* head, int val) {
        ListNode *superhead = new ListNode(0);
        superhead->next = head;
        ListNode *cur = superhead;
        while(cur->next != NULL) {
            if(cur->next->val == val)
                cur->next = cur->next->next;
            else
                cur = cur->next;
            if(cur == NULL) break;
        }
        ListNode *res = superhead->next;
        delete superhead;
        return res;
    }
};
