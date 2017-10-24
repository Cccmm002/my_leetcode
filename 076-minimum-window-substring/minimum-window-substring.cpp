// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
//
//
// For example,
// S = "ADOBECODEBANC"
// T = "ABC"
//
//
// Minimum window is "BANC".
//
//
//
// Note:
// If there is no such window in S that covers all characters in T, return the empty string "".
//
//
// If there are multiple such windows, you are guaranteed that there will always be only one unique minimum window in S.


class Solution {
private:
    inline bool contain(unordered_map<char, int> &window, unordered_map<char, int>& wt) {
        auto it = wt.begin();
        while (it != wt.end()) {
            if (window.find(it->first) == window.end())
                return false;
            if (window[it->first] < it->second)
                return false;
            it++;
        }
        return true;
    }
    
public:
    string minWindow(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        if (ns == 0) return "";
        unordered_map<char, int> window, wt;
        for(char c : t) {
            if (wt.count(c) == 0) wt[c] = 1;
            else wt[c]++;
        }
        int beg = 0, end = 0;
        window[s[0]] = 1;
        int res_len = INT_MAX;
        string res = "";
        while (beg < ns) {
            while (end < ns) {
                if (contain(window, wt)) {
                    if (end - beg + 1 < res_len) {
                        res_len = end - beg + 1;
                        res = s.substr(beg, res_len);
                    }
                    break;
                }
                ++end;
                if (window.count(s[end]) == 0) window[s[end]] = 1;
                else window[s[end]] += 1;
            }
            window[s[beg]] -= 1;
            ++beg;
        }
        if (res_len == INT_MAX) return "";
        else return res;
    }
};
