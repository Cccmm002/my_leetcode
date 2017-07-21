// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. You may assume the dictionary does not contain duplicate words.
//
//
//
// Return all such possible sentences.
//
//
//
// For example, given
// s = "catsanddog",
// dict = ["cat", "cats", "and", "sand", "dog"].
//
//
//
// A solution is ["cats and dog", "cat sand dog"].
//
//
//
// UPDATE (2017/1/4):
// The wordDict parameter had been changed to a list of strings (instead of a set of strings). Please reload the code definition to get the latest changes.


class Solution {
private:
    vector<vector<string>> solve(string s, vector<string> &dict, unordered_map<string, vector<vector<string>>> &map) {
        if (map.find(s) != map.end()) return map[s];
        vector<vector<string>> res;
        if (s == "") return res;
        for (string word : dict) {
            int len = word.size();
            if (s.size() < len)
                continue;
            if (s == word) {
                vector<string> v = {word};
                res.push_back(v);
            }
            if (s.substr(0, len) == word) {
                vector<vector<string>> next = solve(s.substr(len, s.size() - len), dict, map);
                for (vector<string> content : next) {
                    vector<string> cur = {word};
                    for (string w : content) {
                        cur.push_back(w);
                    }
                    res.push_back(cur);
                }
            }
        }
        map[s] = res;
        return res;
    }
    
public:
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, vector<vector<string>>> map;
        vector<vector<string>> v = solve(s, wordDict, map);
        vector<string> res;
        for (vector<string> vs : v) {
            int len = vs.size();
            string st = "";
            for (int i = 0; i < len - 1; ++i)
                st += vs[i] + " ";
            st += vs[len - 1];
            res.push_back(st);
        }
        return res;
    }
};
