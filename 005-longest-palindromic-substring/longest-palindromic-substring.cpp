// Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
// Example 1:
//
//
// Input: "babad"
// Output: "bab"
// Note: "aba" is also a valid answer.
//
//
// Example 2:
//
//
// Input: "cbbd"
// Output: "bb"
//
//


class Solution {
public:
    
string longestPalindrome(string s) {
    int length=s.length();
    if(length==0)
        return "";
    int *r=(int*)malloc(sizeof(int)*length*length);
    memset(r,0,sizeof(int)*length*length);
    int max=1;
    int maxi=0;
    for(int len=1;len<=length;len++)
        for(int i=0;i<length-len+1;i++){
            int j=i+len-1;
            int index=i*length+j;
            if(len==1) {
                r[index] = 1;
                continue;
            }
            if(len==2){
                if(s[i]==s[j]) {
                    r[index] = 1;
                    if(max<len){
                        max=len;
                        maxi=i;
                    }
                }
                continue;
            }
            int previndex=(i+1)*length+j-1;
            if(s[i]==s[j] && r[previndex]==1){
                r[index]=1;
                if(max<len){
                    max=len;
                    maxi=i;
                }
            }
        }
    free(r);
    return s.substr(maxi,max);
}
};
