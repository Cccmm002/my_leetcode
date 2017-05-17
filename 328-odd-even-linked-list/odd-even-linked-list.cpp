// Given a singly linked list, group all odd nodes together followed by the even nodes. Please note here we are talking about the node number and not the value in the nodes.
//
// You should try to do it in place. The program should run in O(1) space complexity and O(nodes) time complexity.
//
//
// Example:
// Given 1->2->3->4->5->NULL,
// return 1->3->5->2->4->NULL.
//
//
// Note:
// The relative order inside both the even and odd groups should remain as it was in the input. 
// The first node is considered odd, the second node even and so on ...
//
//
// Credits:Special thanks to @DjangoUnchained for adding this problem and creating all test cases.


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
    ListNode* oddEvenList(ListNode* head) {
        if (head == NULL) return NULL;
        if (head->next == NULL) return head;
        ListNode *odd = head;
        ListNode *odd_cur = odd;
        ListNode *even = head->next;
        ListNode *even_cur = even;
        ListNode *cur = head->next->next;
        int count = 2;
        while (cur != NULL) {
            count++;
            ListNode *next = cur->next;
            if (count % 2 == 0) {
                cur->next = NULL;
                even_cur->next = cur;
                even_cur = cur;
            }
            else {
                cur->next = NULL;
                odd_cur->next = cur;
                odd_cur = cur;
            }
            cur = next;
        }
        odd_cur->next = even;
        even_cur->next = NULL;
        return odd;
    }
};
