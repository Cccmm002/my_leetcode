// Sort a linked list using insertion sort.


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
    ListNode* insertionSortList(ListNode* head) {
        if (head == NULL) return NULL;
        ListNode *superRoot = new ListNode(-1);
        superRoot->next = head;
        ListNode *cur = head;
        ListNode *prev = superRoot;
        ListNode *next = head->next;
        while (cur != NULL) {
            ListNode *search = superRoot->next;
            ListNode *sprev = superRoot;
            next = cur->next;
            while (true) {
                if (cur == search) {
                    prev = cur;
                    cur = next;
                    break;
                }
                if (search->val <= cur->val) {
                    sprev = search;
                    search = search->next;
                }
                else {
                    prev->next = next;
                    cur->next = search;
                    sprev->next = cur;
                    
                    cur = next;
                    break;
                }
            }
        }
        ListNode *res = superRoot->next;
        delete superRoot;
        return res;
    }
};
