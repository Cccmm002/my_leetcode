// Given an integer n, return 1 - n in lexicographical order.
//
//
//
// For example, given 13, return: [1,10,11,12,13,2,3,4,5,6,7,8,9].
//
//
//
// Please optimize your algorithm to use less time and space. The input size may be as large as 5,000,000.


class Solution {
private:
    void calc(int current, int limit, vector<int> &res) {
        for (int i = 0; i < 10; i++) {
            int cur = current*10 + i;
            if (cur > limit) continue;
            res.push_back(cur);
            calc(cur, limit, res);
        }
    }

public:
    vector<int> lexicalOrder(int n) {
        vector<int> res;
        for (int i = 1; i < 10; i++) {
            if (i > n) continue;
            res.push_back(i);
            calc(i, n, res);
        }
        return res;
    }
};
