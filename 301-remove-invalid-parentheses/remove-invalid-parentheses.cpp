// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
// Note: The input string may contain letters other than the parentheses ( and ).
//
// Example 1:
//
//
// Input: "()())()"
// Output: ["()()()", "(())()"]
//
//
// Example 2:
//
//
// Input: "(a)())()"
// Output: ["(a)()()", "(a())()"]
//
//
// Example 3:
//
//
// Input: ")("
// Output: [""]
//
//


class Solution {
private:
    inline bool valid(string s) {
        int n = s.size();
        int c = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')')
                continue;
            if (s[i] == '(')
                c++;
            if (s[i] == ')') {
                c--;
                if (c < 0)
                    return false;
            }
        }
        return c == 0;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        if (valid(s)) return {s};
        unordered_set<string> visited;
        vector<string> res;
        queue<string> q;
        q.push(s);
        visited.insert(s);
        while (!q.empty()) {
            if (res.size() > 0)
                return res;
            int queue_count = q.size();
            for (int i = 0; i < queue_count; i++) {
                string cur = q.front();
                q.pop();
                if (valid(cur)) {
                    res.push_back(cur);
                }
                else {
                    int len = cur.size();
                    for (int k = 0; k < len; k++) {
                        if (cur[k] != '(' && cur[k] != ')')
                            continue;
                        string ns = cur.substr(0, k) + cur.substr(k + 1, len - k - 1);
                        if (visited.find(ns) != visited.end())
                            continue;
                        visited.insert(ns);
                        q.push(ns);
                    }
                }
            }
        }
        return res;
    }
};
