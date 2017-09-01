// Remove the minimum number of invalid parentheses in order to make the input string valid. Return all possible results.
//
// Note: The input string may contain letters other than the parentheses ( and ). 
//
//
//
// Examples:
//
// "()())()" -> ["()()()", "(())()"]
// "(a)())()" -> ["(a)()()", "(a())()"]
// ")(" -> [""]
//
//
//
// Credits:Special thanks to @hpplayer for adding this problem and creating all test cases.


class Solution {
private:
    unordered_map<string, pair<int, unordered_set<string>>> dict;
    
    inline bool valid(string s) {
        int n = s.size();
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') count++;
            else if (s[i] == ')') count--;
            if (count < 0) return false;
        }
        return count == 0;
    }
    
    unordered_set<string> find(string s, int *res) {
        if (dict.find(s) != dict.end()) {
            *res = dict[s].first;
            return dict[s].second;
        }
        unordered_set<string> rss;
        if (valid(s)) {
            rss.insert(s);
            dict[s] = make_pair(0, rss);
            *res = 0;
            return rss;
        }
        int n = s.size();
        int r = INT_MAX;
        for (int i = 0; i < n; i++) {
            if (s[i] != '(' && s[i] != ')') continue;
            string next = s.substr(0, i) + s.substr(i + 1, n - i - 1);
            int next_res;
            unordered_set<string> us = find(next, &next_res);
            if (next_res == r) {
                for (string st : us) rss.insert(st);
            }
            else if (next_res < r) {
                r = next_res;
                rss = us;
            }
        }
        *res = r + 1;
        dict[s] = make_pair(r + 1, rss);
        return rss;
    }
    
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        int count;
        unordered_set<string> r = find(s, &count);
        for (string st : r) res.push_back(st);
        return res;
    }
};
