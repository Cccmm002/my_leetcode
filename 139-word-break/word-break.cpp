// Given a non-empty string s and a dictionary wordDict containing a list of non-empty words, determine if s can be segmented into a space-separated sequence of one or more dictionary words.
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
// Input: s = "leetcode", wordDict = ["leet", "code"]
// Output: true
// Explanation: Return true because "leetcode" can be segmented as "leet code".
//
//
// Example 2:
//
//
// Input: s = "applepenapple", wordDict = ["apple", "pen"]
// Output: true
// Explanation: Return true because "applepenapple" can be segmented as "apple pen apple".
//              Note that you are allowed to reuse a dictionary word.
//
//
// Example 3:
//
//
// Input: s = "catsandog", wordDict = ["cats", "dog", "sand", "and", "cat"]
// Output: false
//
//


class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        unordered_set<string> words;
        for (string w : wordDict) words.insert(w);
        vector<bool> arr(n + 1, false);
        arr[0] = true;
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t < i;t++) {
                if (!arr[t]) continue;
                string sub = s.substr(t, i - t);
                if (words.find(sub) != words.end()) {
                    arr[i] = true;
                    break;
                }
                arr[i] = false;
            }
        }
        return arr[n];
    }
};
