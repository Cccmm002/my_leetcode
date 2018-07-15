//
// Given a string s and a string t, check if s is subsequence of t.
//
//
//
// You may assume that there is only lower case English letters in both s and t. t is potentially a very long (length ~= 500,000) string, and s is a short string (<=100).
//
//
//
// A subsequence of a string is a new string which is formed from the original string by deleting some (can be none) of the characters without disturbing the relative positions of the remaining characters. (ie, "ace" is a subsequence of "abcde" while "aec" is not).
//
//
// Example 1:
// s = "abc", t = "ahbgdc"
//
//
// Return true.
//
//
// Example 2:
// s = "axc", t = "ahbgdc"
//
//
// Return false.
//
//
// Follow up:
// If there are lots of incoming S, say S1, S2, ... , Sk where k >= 1B, and you want to check one by one to see if T has its subsequence. In this scenario, how would you change your code?
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


public class Solution {
    public boolean isSubsequence(String s, String t) {
        if(s.length() <= 0)
            return true;
        else if(t.length() <= 0)
            return false;
        
        boolean[] arr1 = new boolean[s.length()];
        boolean[] arr2 = new boolean[s.length()];
        arr1[0] = s.charAt(0) == t.charAt(0);
        for(int j = 1; j<t.length();j++) {
            if(s.charAt(0) == t.charAt(j))
                arr2[0] = true;
            else
                arr2[0] = arr1[0];
            for(int i = 1;i<s.length();i++) {
                if(i > j)
                    arr2[i] = false;
                else {
                    if(s.charAt(i) == t.charAt(j))
                        arr2[i] = arr1[i-1];
                    else
                        arr2[i] = arr1[i];
                }
            }
            System.arraycopy(arr2, 0, arr1, 0, arr2.length);
        }
        return arr2[s.length()-1];
    }
}
