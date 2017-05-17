// Given a string containing only digits, restore it by returning all possible valid IP address combinations.
//
//
// For example:
// Given "25525511135",
//
//
// return ["255.255.11.135", "255.255.111.35"]. (Order does not matter)


class Solution {
private:
    vector<string> test(string s, int lastTests) {
        vector<string> empty;
        int len=s.length();
        if(len==0) return empty;
        if(lastTests==1){
            if(len>3) return empty;
            if(len!=1&&s[0]=='0') return empty;
            int num=stoi(s);
            if(num<=255){
                vector<string> res;
                res.push_back(s);
                return res;
            }
            else
                return empty;
        }
        else if(lastTests==2){
            if(len>6) return empty;
        }
        else if(lastTests==3){
            if(len>9) return empty;
        }
        else if(len>12) return empty;
        vector<string> res;
        for(int i=1;i<=3;i++){
            if(i>len) break;
            string subs=s.substr(0,i);
            if(i!=1&&s[0]=='0') continue;
            if(i==3&&stoi(subs)>255) continue;
            vector<string> v=test(s.substr(i),lastTests-1);
            for(string ss:v)
                res.push_back(s.substr(0,i)+"."+ss);
        }
        return res;
    }
public:
    vector<string> restoreIpAddresses(string s) {
        return test(s,4);
    }
};
