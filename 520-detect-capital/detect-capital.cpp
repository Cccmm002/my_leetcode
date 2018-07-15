//
// Given a word, you need to judge whether the usage of capitals in it is right or not.
//
//
//
// We define the usage of capitals in a word to be right when one of the following cases holds:
//
// All letters in this word are capitals, like "USA".
// All letters in this word are not capitals, like "leetcode".
// Only the first letter in this word is capital if it has more than one letter, like "Google".
//
// Otherwise, we define that this word doesn't use capitals in a right way.
//
//
//
// Example 1:
//
// Input: "USA"
// Output: True
//
//
//
// Example 2:
//
// Input: "FlaG"
// Output: False
//
//
//
// Note:
// The input will be a non-empty word consisting of uppercase and lowercase latin letters.
//


class Solution {
private:
    inline bool capital(char c) {
        return (c >= 'A' && c <= 'Z');
    }
    
public:
    bool detectCapitalUse(string word) {
        int len = word.size();
        if (len <= 1) return true;
        bool first = capital(word[0]);
        bool second = capital(word[1]);
        if (!first && second) return false;
        for (int i = 2; i < len; i++) {
            bool cur = capital(word[i]);
            if (!second) {
                if (cur) return false;
            }
            if (second && first) {
                if (!cur) return false;
            }
        }
        return true;
    }
};
