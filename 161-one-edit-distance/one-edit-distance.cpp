// Given two strings s and t, determine if they are both one edit distance apart.
//
// Note: 
//
// There are 3 possiblities to satisify one edit distance apart:
//
//
// 	Insert a character into s to get t
// 	Delete a character from s to get t
// 	Replace a character of s to get t
//
//
// Example 1:
//
//
// Input: s = "ab", t = "acb"
// Output: true
// Explanation: We can insert 'c' into s to get t.
//
//
// Example 2:
//
//
// Input: s = "cab", t = "ad"
// Output: false
// Explanation: We cannot get t from s by only one step.
//
// Example 3:
//
//
// Input: s = "1203", t = "1213"
// Output: true
// Explanation: We can replace '0' with '1' to get t.
//


class Solution {
public:
    bool isOneEditDistance(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (abs(lens - lent) > 1) return false;
        int p1 = 0;
        int p2 = 0;
        int meet = 0;
        while (p1 < lens && p2 < lent) {
            if (s[p1] != t[p2]) {
                if (meet >= 1) return false;
                meet = 1;
                if (lens == lent) {
                    p1++;
                    p2++;
                }
                else if (lens > lent) {
                    p1++;
                }
                else {
                    p2++;
                }
            }
            else {
                p1++;
                p2++;
            }
        }
        if (lens == lent)
            return meet == 1;
        else if (p1 == p2)
            return meet == 0;
        else
            return meet == 1;
    }
};
