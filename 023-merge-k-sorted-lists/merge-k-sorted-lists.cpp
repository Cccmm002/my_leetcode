// Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.


/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
private:
    typedef struct Element {
        int value;
        int listNum;
        
        Element(int v, int l) : value(v), listNum(l) {}
    }*pElement;
    
    class Compare {
    public:
        bool operator() (const Element &a, const Element &b) {
            return a.value > b.value;
        }
    };
    
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int listCount = lists.size();
        priority_queue<Element, vector<Element>, Compare> q;
        for (int i=0; i<listCount; i++) {
            if (lists[i] == NULL)
                continue;
            q.push(Element(lists[i]->val, i));
            lists[i] = lists[i]->next;
        }
        vector<int> res;
        while (!q.empty()) {
            Element cur = q.top();
            q.pop();
            res.push_back(cur.value);
            int lc = cur.listNum;
            if(lists[lc] != NULL) {
                q.push(Element(lists[lc]->val, lc));
                lists[lc] = lists[lc]->next;
            }
        }
        
        if (res.size() == 0) return NULL;
        ListNode *root = new ListNode(res[0]);
        ListNode *curn = root;
        for (int i=1;i<res.size();i++) {
            ListNode *ln = new ListNode(res[i]);
            curn->next = ln;
            curn = curn->next;
        }
        return root;
    }
};
