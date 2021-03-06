//
// Given two strings s and t which consist of only lowercase letters.
//
// String t is generated by random shuffling string s and then add one more letter at a random position.
//
// Find the letter that was added in t.
//
// Example:
//
// Input:
// s = "abcd"
// t = "abcde"
//
// Output:
// e
//
// Explanation:
// 'e' is the letter that was added.
//


class Solution {
public:
    char findTheDifference(string s, string t) {
    int cs[26];
    int ct[26];
    for(int i=0;i<26;i++){
        cs[i]=0;
        ct[i]=0;
    }
    for(int i=0;i<s.length();i++)
        cs[s[i]-'a']++;
    for(int i=0;i<t.length();i++)
        ct[t[i]-'a']++;
    char res;
    for(int i=0;i<26;i++){
        if(cs[i]!=ct[i]){
            res='a'+i;
            break;
        }
    }
    return res;
}
};
