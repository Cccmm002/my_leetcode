//
// A linked list is given such that each node contains an additional random pointer which could point to any node in the list or null.
//
//
//
// Return a deep copy of the list.
//


/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
class Solution {
public:
    RandomListNode *copyRandomList(RandomListNode *head) {
        if (head == NULL) return NULL;
        unordered_map<RandomListNode*, RandomListNode*> m;
        RandomListNode *superRoot = new RandomListNode(-1);
        superRoot->next = head;
        RandomListNode *superNewRoot = new RandomListNode(-1);
        RandomListNode *prev = superNewRoot;
        RandomListNode *cur = superRoot->next;
        while (cur != NULL) {
            auto it = m.find(cur);
            if (it == m.end()) {
                RandomListNode *n = new RandomListNode(cur->label);
                prev->next = n;
                m[cur] = n;
                RandomListNode *rcur = cur;
                while (rcur->random != NULL) {
                    auto rit = m.find(rcur->random);
                    if (rit == m.end()) {
                        RandomListNode *rn = new RandomListNode(rcur->random->label);
                        m[rcur->random] = rn;
                        n->random = rn;
                        n = rn;
                        rcur = rcur->random;
                    }
                    else {
                        n->random = m[rcur->random];
                        break;
                    }
                }
            }
            else {
                prev->next = m[cur];
            }
            prev = prev->next;
            cur = cur->next;
        }
        RandomListNode *res = superNewRoot->next;
        delete superRoot;
        delete superNewRoot;
        return res;
    }
};
