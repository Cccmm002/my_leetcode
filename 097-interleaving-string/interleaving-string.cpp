// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.
//
// Example 1:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true
//
//
// Example 2:
//
//
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false
//
//


class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int l1 = s1.size();
        int l2 = s2.size();
        int l3 = s3.size();
        if (l3 == 0) {
            if (l1 == 0 && l2 == 0) return true;
            else return false;
        }
        if (l1 == 0) return s2 == s3;
        if (l2 == 0) return s1 == s3;
        if (l1 + l2 != l3) return false;
        bool **f = new bool*[l1+1];
        for (int i=0;i<=l1;i++)
            f[i] = new bool[l2+1];
        f[0][0] = true;
        for (int i=1;i<=l1;i++)
            f[i][0] = s3[i-1] == s1[i-1]?f[i-1][0]:false;
        for (int i=1;i<=l2;i++)
            f[0][i] = s3[i-1] == s2[i-1]?f[0][i-1]:false;
        for (int i=1;i<=l1;i++) {
            for (int j=1;j<=l2;j++) {
                bool r = false;
                if (s3[i+j-1] == s1[i-1])
                    r = r || f[i-1][j];
                if (s3[i+j-1] == s2[j-1])
                    r = r || f[i][j-1];
                f[i][j] = r;
            }
        }
        return f[l1][l2];
    }
};
