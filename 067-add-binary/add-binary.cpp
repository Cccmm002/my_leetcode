// Given two binary strings, return their sum (also a binary string).
//
// The input strings are both non-empty and contains only characters 1 or 0.
//
// Example 1:
//
//
// Input: a = "11", b = "1"
// Output: "100"
//
// Example 2:
//
//
// Input: a = "1010", b = "1011"
// Output: "10101"
//


class Solution {
public:
    string addBinary(string a, string b) {
        string rres="";
        int pa=a.length()-1;
        int pb=b.length()-1;
        int incre=0;
        while(pa>=0 || pb>=0) {
            int ca=0;
            int cb=0;
            if(pa>=0) {
                ca=a[pa]-'0';
                pa--;
            }
            if(pb>=0) {
                cb=b[pb]-'0';
                pb--;
            }
            int sum=ca+cb+incre;
            incre=sum/2;
            sum=sum%2;
            rres+=('0'+sum);
        }
        if(incre!=0)
            rres+='1';
        if(rres.length()==1)
            return rres;
        string res="";
        int i=rres.length()-1;
        while(rres[i]=='0') i--;
        for(;i>=0;i--)
            res+=rres[i];
        return res;
    }
};
