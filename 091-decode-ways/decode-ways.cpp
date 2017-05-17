// A message containing letters from A-Z is being encoded to numbers using the following mapping:
//
//
//
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
//
//
//
// Given an encoded message containing digits, determine the total number of ways to decode it.
//
//
//
// For example,
// Given encoded message "12",
// it could be decoded as "AB" (1 2) or "L" (12).
//
//
//
// The number of ways decoding "12" is 2.


class Solution {
public:
    int solve(string s, map<int,int>& m, bool *failed){
        int len=s.length();
        if(len==0) return 1;
        if(len==1 && s!="0") return 1;
        if(len==1 && s=="0") return 0;
        auto it=m.find(len);
        if(it!=m.end()) return it->second;
        int num=s[0]-'0';
        int numNext=s[1]-'0';
        if(num==0||((num>=3&&num<=9)&&numNext==0)){
            *failed=true;
            return 0;
        }
        if(numNext!=0&&((num==1)||(num==2&&numNext<=6))){
            int res=solve(s.substr(1),m,failed)+solve(s.substr(2),m,failed);
            m[len]=res;
            return res;
        }
        if(numNext==0&&num<=2){
            int res=solve(s.substr(2),m,failed);
            m[len]=res;
            return res;
        }
        int res=solve(s.substr(1),m,failed);
        m[len]=res;
        return res;
    }

    int numDecodings(string s) {
        if(s.length()==0) return 0;
        map<int,int> m;
        bool failed=false;
        int res=solve(s,m,&failed);
        if(failed)
            return 0;
        else
            return res;
    }
};
