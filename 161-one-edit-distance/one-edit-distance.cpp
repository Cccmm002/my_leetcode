// Given two strings S and T, determine if they are both one edit distance apart.


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
