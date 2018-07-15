// Given a string array words, find the maximum value of length(word[i]) * length(word[j]) where the two words do not share common letters. You may assume that each word will contain only lower case letters. If no such two words exist, return 0.
//
// Example 1:
//
//
// Input: ["abcw","baz","foo","bar","xtfn","abcdef"]
// Output: 16 
// Explanation: The two words can be "abcw", "xtfn".
//
// Example 2:
//
//
// Input: ["a","ab","abc","d","cd","bcd","abcd"]
// Output: 4 
// Explanation: The two words can be "ab", "cd".
//
// Example 3:
//
//
// Input: ["a","aa","aaa","aaaa"]
// Output: 0 
// Explanation: No such pair of words.
//
//


class Solution {
public:
    int maxProduct(vector<string>& words) {
        vector<int> bits;
        for (string w : words) {
            int len = w.size();
            int cur = 0;
            for (int i = 0; i < len; i++) {
                int digit = w[i] - 'a';
                cur |= (1 << digit);
            }
            bits.push_back(cur);
        }
        int len = words.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            for (int j = i + 1; j < len; j++) {
                if ((bits[i] & bits[j]) != 0) continue;
                res = max(res, (int)(words[i].size()*words[j].size()));
            }
        }
        return res;
    }
};
