// Given a list accounts, each element accounts[i] is a list of strings, where the first element accounts[i][0] is a name, and the rest of the elements are emails representing emails of the account.
//
// Now, we would like to merge these accounts.  Two accounts definitely belong to the same person if there is some email that is common to both accounts.  Note that even if two accounts have the same name, they may belong to different people as people could have the same name.  A person can have any number of accounts initially, but all of their accounts definitely have the same name.
//
// After merging the accounts, return the accounts in the following format: the first element of each account is the name, and the rest of the elements are emails in sorted order.  The accounts themselves can be returned in any order.
//
// Example 1:
//
// Input: 
// accounts = [["John", "johnsmith@mail.com", "john00@mail.com"], ["John", "johnnybravo@mail.com"], ["John", "johnsmith@mail.com", "john_newyork@mail.com"], ["Mary", "mary@mail.com"]]
// Output: [["John", 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com'],  ["John", "johnnybravo@mail.com"], ["Mary", "mary@mail.com"]]
// Explanation: 
// The first and third John's are the same person as they have the common email "johnsmith@mail.com".
// The second John and Mary are different people as none of their email addresses are used by other accounts.
// We could return these lists in any order, for example the answer [['Mary', 'mary@mail.com'], ['John', 'johnnybravo@mail.com'], 
// ['John', 'john00@mail.com', 'john_newyork@mail.com', 'johnsmith@mail.com']] would still be accepted.
//
//
//
// Note:
// The length of accounts will be in the range [1, 1000].
// The length of accounts[i] will be in the range [1, 10].
// The length of accounts[i][j] will be in the range [1, 30].
//


class UnionFind {
private:
    int *parents;
    int num;

public:
    UnionFind(int n) {
        num = n;
        parents = new int[n];
        for(int i=0;i<n;i++)
            parents[i] = i;
    }
    
    int findSet(int n) {
        if(parents[n] == n)
            return n;
        int p = findSet(parents[n]);
        parents[n] = p;
        return p;
    }
    
    void connect(int x, int y) {
        int a = findSet(x);
        int b = findSet(y);
        if (a != b)
            parents[a] = b;
    }
    
    ~UnionFind() {
        delete[] parents;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        UnionFind *uf = new UnionFind(n);
        unordered_map<string, int> ump;
        unordered_map<int, unordered_set<string>> reverse;
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                if (ump.count(s) == 0) {
                    ump[s] = i;
                }
                else {
                    uf->connect(ump[s], i);
                }
            }
        }
        for (int i = 0; i < n; i++) {
            int id = uf->findSet(i);
            if (reverse.find(id) == reverse.end()) {
                unordered_set<string> set;
                reverse[id] = set;
            }
            for (int j = 1; j < accounts[i].size(); j++) {
                string s = accounts[i][j];
                reverse[id].insert(s);
            }
        }
        vector<vector<string>> res;
        auto it = reverse.begin();
        while (it != reverse.end()) {
            vector<string> cur;
            for (const auto &s : it->second) {
                cur.push_back(s);
            }
            sort(cur.begin(), cur.end());
            cur.insert(cur.begin(), accounts[it->first][0]);
            res.push_back(cur);
            it++;
        }
        delete uf;
        return res;
    }
};
