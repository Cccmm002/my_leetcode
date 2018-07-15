// A gene string can be represented by an 8-character long string, with choices from "A", "C", "G", "T".
//
// Suppose we need to investigate about a mutation (mutation from "start" to "end"), where ONE mutation is defined as ONE single character changed in the gene string.
//
// For example, "AACCGGTT" -> "AACCGGTA" is 1 mutation.
//
// Also, there is a given gene "bank", which records all the valid gene mutations. A gene must be in the bank to make it a valid gene string.
//
// Now, given 3 things - start, end, bank, your task is to determine what is the minimum number of mutations needed to mutate from "start" to "end". If there is no such a mutation, return -1.
//
// Note:
//
//
// 	Starting point is assumed to be valid, so it might not be included in the bank.
// 	If multiple mutations are needed, all mutations during in the sequence must be valid.
// 	You may assume start and end string is not the same.
//
//
//  
//
// Example 1:
//
//
// start: "AACCGGTT"
// end:   "AACCGGTA"
// bank: ["AACCGGTA"]
//
// return: 1
//
//
//  
//
// Example 2:
//
//
// start: "AACCGGTT"
// end:   "AAACGGTA"
// bank: ["AACCGGTA", "AACCGCTA", "AAACGGTA"]
//
// return: 2
//
//
//  
//
// Example 3:
//
//
// start: "AAAAACCC"
// end:   "AACCCCCC"
// bank: ["AAAACCCC", "AAACCCCC", "AACCCCCC"]
//
// return: 3
//
//
//  
//


class Solution {
public:
    typedef struct Node {
        string gene;
        int mutate;
        Node(string s,int m):gene(s),mutate(m){}
    }*pNode;

    int minMutation(string start, string end, vector<string>& bank) {
        unordered_set<string> dic, visited;
        queue<pNode> q;
        for(string s:bank) 
            dic.insert(s);
        q.push(new Node(start,0));
        visited.insert(start);
        while(!q.empty()) {
            pNode curNode=q.front();
            string cur=curNode->gene;
            q.pop();
            for(int i=0;i<8;i++) {
                char g[4]={'A','T','G','C'};
                for(int j=0;j<4;j++) {
                    if(cur[i]==g[j]) continue;
                    string ns=cur;
                    ns[i]=g[j];
                    auto it_dic=dic.find(ns);
                    if(it_dic==dic.end()) continue;
                    auto it_v=visited.find(ns);
                    if(it_v!=visited.end()) continue;
                    if(ns==end) return curNode->mutate+1;
                    visited.insert(ns);
                    q.push(new Node(ns,curNode->mutate+1));
                }
            }
        }
        return -1;
    }
};
