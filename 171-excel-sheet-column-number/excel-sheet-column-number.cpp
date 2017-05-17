// Related to question Excel Sheet Column Title
// Given a column title as appear in an Excel sheet, return its corresponding column number.
//
// For example:
//     A -&gt; 1
//     B -&gt; 2
//     C -&gt; 3
//     ...
//     Z -&gt; 26
//     AA -&gt; 27
//     AB -&gt; 28 
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int titleToNumber(string s) {
        int res=0;
        int len=s.length();
        for(int i=0;i<len;i++) {
            res*=26;
            res+=s[i]-'A'+1;
        }
        return res;
    }
};
