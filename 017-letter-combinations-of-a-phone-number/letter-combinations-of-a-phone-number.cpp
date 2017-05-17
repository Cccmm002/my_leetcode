// Given a digit string, return all possible letter combinations that the number could represent.
//
//
//
// A mapping of digit to letters (just like on the telephone buttons) is given below.
//
//
//
// Input:Digit string "23"
// Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
//
//
//
// Note:
// Although the above answer is in lexicographical order, your answer could be in any order you want.


class Solution {
public:
    vector<string> letterCombinations(string digits) {
    string map[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    int len=digits.length();
    vector<string> res;
    if(len==0) return res;
    queue<string> q;
    q.push("");
    while(!q.empty()){
        string s=q.front();
        q.pop();
        if(s.length()==len)
            res.push_back(s);
        else{
            int l=s.length();
            int c=digits[l]-'0';
            string alternation=map[c];
            for(int i=0;i<alternation.length();i++)
                q.push(s+alternation[i]);
        }
    }
    return res;
}
};
