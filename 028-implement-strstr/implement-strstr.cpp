// Implement strStr().
//
//
// Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


class Solution {
public:
    int strStr(string haystack, string needle) {
        int len1=haystack.length();
        int len2=needle.length();
        if(len1<len2) return -1;
        for(int i=0;i<=len1-len2;i++){
            string sub=haystack.substr(i,len2);
            if(sub==needle)
                return i;
        }
        return -1;
    }
};
