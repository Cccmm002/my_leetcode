// Given a string S and a string T, find the minimum window in S which will contain all the characters in T in complexity O(n).
//
// Example:
//
//
// Input: S = "ADOBECODEBANC", T = "ABC"
// Output: "BANC"
//
//
// Note:
//
//
// 	If there is no such window in S that covers all characters in T, return the empty string "".
// 	If there is such window, you are guaranteed that there will always be only one unique minimum window in S.
//
//


class Solution {
public:
    string minWindow(string s, string t) {
        int ns = s.size();
        int nt = t.size();
        unordered_map<char, int> m;
        for (int i = 0; i < nt; i++) {
            char c = t[i];
            if (m.find(c) == m.end())
                m[c] = 0;
            m[c] += 1;
        }
        int begin = 0, end = 0;
        int wlen = ns + 1;
        string window = "";
        while (end < ns) {
            char c = s[end];
            if (m.find(c) != m.end()) {
                m[c] -= 1;
                if (m[c] >= 0) nt -= 1;
            }
            while (nt == 0 && begin <= end) {
                int l = end - begin + 1;
                if (l < wlen) {
                    wlen = l;
                    window = s.substr(begin, l);
                }
                char b = s[begin];
                if (m.find(b) != m.end()) {
                    m[b] += 1;
                    if (m[b] > 0) nt += 1;
                }
                begin += 1;
            }
            end += 1;
        }
        return window;
    }
};
