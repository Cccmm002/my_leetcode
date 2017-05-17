// Given an array of strings, group anagrams together.
//
//
// For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"], 
// Return:
//
// [
//   ["ate", "eat","tea"],
//   ["nat","tan"],
//   ["bat"]
// ]
//
// Note: All inputs will be in lower-case.


class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> m;
        for(string s:strs){
            int slen=s.length();
            char *c=(char*)malloc(sizeof(char)*slen);
            for(int i=0;i<slen;i++) c[i]=s[i];
            sort(c,c+slen);
            string snew(c,slen);
            auto it=m.find(snew);
            if(it==m.end()){
                vector<string> v;
                v.push_back(s);
                m[snew]=v;
            }
            else{
                it->second.push_back(s);
            }
        }
        vector<vector<string>> res;
        auto it=m.begin();
        while(it!=m.end()){
            sort(it->second.begin(),it->second.end());
            res.push_back(it->second);
            it++;
        }
        return res;
    }
};
