// Given a string s, partition s such that every substring of the partition is a palindrome.
//
// Return all possible palindrome partitioning of s.
//
// Example:
//
//
// Input: "aab"
// Output:
// [
//   ["aa","b"],
//   ["a","a","b"]
// ]
//
//


class Solution {
private:
    inline bool palindrome(string s) {
        int len=s.length();
        if(len==0) return false;
        if(len==1) return true;
        int begin=0, end=len-1;
        while(begin<end){
            if(s[begin]!=s[end]) return false;
            begin++;
            end--;
        }
        return true;
    }
public:
    vector<vector<string>> partition(string s) {
        vector<string> empty;
        vector<vector<string>> res;
        int len=s.length();
        if(len==0) {
            res.push_back(empty);
            return res;
        }
        for(int i=1;i<=len;i++){
            string subs=s.substr(0,i);
            if(!palindrome(subs)) continue;
            vector<vector<string>> last=partition(s.substr(i));
            for(vector<string> v:last){
                v.insert(v.begin(),subs);
                res.push_back(v);
            }
        }
        return res;
    }
};
