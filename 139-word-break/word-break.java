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
    public boolean wordBreak(String s, List<String> wordDict) {
        int n = s.length();
        HashSet<String> set = new HashSet<String>(wordDict);
        boolean[] dp = new boolean[n + 1];
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            dp[i + 1] = false;
            for (int j = 0; j <= i; j++) {
                if (!dp[j]) continue;
                String w = s.substring(j, i + 1);
                if (set.contains(w)) {
                    dp[i + 1] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
}
