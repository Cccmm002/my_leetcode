// A group of friends went on holiday and sometimes lent each other money. For example, Alice paid for Bill's lunch for $10. Then later Chris gave Alice $5 for a taxi ride. We can model each transaction as a tuple (x, y, z) which means person x gave person y $z. Assuming Alice, Bill, and Chris are person 0, 1, and 2 respectively (0, 1, 2 are the person's ID), the transactions can be represented as [[0, 1, 10], [2, 0, 5]].
//
// Given a list of transactions between a group of people, return the minimum number of transactions required to settle the debt.
//
// Note:
//
// A transaction will be given as a tuple (x, y, z). Note that x ≠ y and z > 0.
// Person's IDs may not be linear, e.g. we could have the persons 0, 1, 2 or we could also have the persons 0, 2, 6.
//
//
//
// Example 1:
//
// Input:
// [[0,1,10], [2,0,5]]
//
// Output:
// 2
//
// Explanation:
// Person #0 gave person #1 $10.
// Person #2 gave person #0 $5.
//
// Two transactions are needed. One way to settle the debt is person #1 pays person #0 and #2 $5 each.
//
//
//
// Example 2:
//
// Input:
// [[0,1,10], [1,0,1], [1,2,5], [2,0,5]]
//
// Output:
// 1
//
// Explanation:
// Person #0 gave person #1 $10.
// Person #1 gave person #0 $1.
// Person #1 gave person #2 $5.
// Person #2 gave person #0 $5.
//
// Therefore, person #1 only need to give person #0 $4, and all debt is settled.
//
//


class Solution {
private:
    int dfs(vector<int> v, int p) {
        int n = v.size();
        if (p >= n - 1) return 0;
        if (v[p] == 0) return dfs(v, p + 1);
        bool positive = v[p] > 0;
        int res = INT_MAX;
        for (int i = p + 1; i < n; i++) {
            if (positive == (v[i] > 0)) continue;
            v[i] += v[p];
            int r = 1 + dfs(v, p + 1);
            v[i] -= v[p];
            res = min(res, r);
        }
        return res;
    }
    
public:
    int minTransfers(vector<vector<int>>& transactions) {
        int maxIndex = -1;
        unordered_map<int, int> m;
        for (vector<int> t : transactions) {
            if (m.find(t[0]) == m.end()) m[t[0]] = 0 - t[2];
            else m[t[0]] -=t[2];
            if (m.find(t[1]) == m.end()) m[t[1]] = t[2];
            else m[t[1]] +=t[2];
            maxIndex = max(maxIndex, max(t[0], t[1]));
        }
        vector<int> v(maxIndex + 1, 0);
        for (int i = 0; i <= maxIndex; i++) v[i] = m[i];
        return dfs(v, 0);
    }
};
