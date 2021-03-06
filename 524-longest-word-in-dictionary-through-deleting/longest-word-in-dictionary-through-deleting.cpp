//
// Given a string and a string dictionary, find the longest string in the dictionary that can be formed by deleting some characters of the given string. If there are more than one possible results, return the longest word with the smallest lexicographical order. If there is no possible result, return the empty string.
//
// Example 1:
//
// Input:
// s = "abpcplea", d = ["ale","apple","monkey","plea"]
//
// Output: 
// "apple"
//
//
//
//
// Example 2:
//
// Input:
// s = "abpcplea", d = ["a","b","c"]
//
// Output: 
// "a"
//
//
//
// Note:
//
// All the strings in the input will only contain lower-case letters.
// The size of the dictionary won't exceed 1,000.
// The length of all the strings in the input won't exceed 1,000.
//
//


class Solution {
public:
    string findLongestWord(string s, vector<string>& d) {
        sort(d.begin(), d.end(), 
            [](const string &a, const string &b) -> bool {
                if(a.length() == b.length()) {
                    return a.compare(b) < 0 ? true : false;
                }
                else {
                    return a.length() > b.length();
                }
            });
        int sl = s.length();
        for(string str : d) {
            int p1 = 0, p2 = 0;
            while (p1 < sl) {
                if(str[p2] == s[p1]) p2++;
                if(p2 == str.length()) return str;
                p1++;
            }
        }
        return "";
    }
};
