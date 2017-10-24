// Given a string, find the length of the longest substring without repeating characters.
//
// Examples:
//
// Given "abcabcbb", the answer is "abc", which the length is 3.
//
// Given "bbbbb", the answer is "b", with the length of 1.
//
// Given "pwwkew", the answer is "wke", with the length of 3. Note that the answer must be a substring, "pwke" is a subsequence and not a substring.


class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0) return 0;
        if (n == 1) return 1;
        unordered_set<char> usc;
        int beg = 0, end = 0;
        //usc.insert(s[0]);
        int res = 0;
        while (beg < n) {
            while (end < n) {
                if (usc.find(s[end]) != usc.end()) {
                    break;
                }
                usc.insert(s[end]);
                ++end;
                res = max(res, end - beg);
            }
            usc.erase(s[beg]);
            ++beg;
        }
        return res;
    }
};
