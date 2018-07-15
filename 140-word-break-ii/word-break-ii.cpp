// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, add spaces in s to construct a sentence where each word is a valid dictionary word. Return all such possible sentences.
//
// Note:
//
//
// 	The same word in the dictionary may be reused multiple times in the segmentation.
// 	You may assume the dictionary does not contain duplicate words.
//
//
// Example 1:
//
//
// Input:
// s = "catsanddog"
// wordDict = ["cat", "cats", "and", "sand", "dog"]
// Output:
// [
//   "cats and dog",
//   "cat sand dog"
// ]
//
//
// Example 2:
//
//
// Input:
// s = "pineapplepenapple"
// wordDict = ["apple", "pen", "applepen", "pine", "pineapple"]
// Output:
// [
//   "pine apple pen apple",
//   "pineapple pen apple",
//   "pine applepen apple"
// ]
// Explanation: Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input:
// s = "catsandog"
// wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output:
// []
//


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
