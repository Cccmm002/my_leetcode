//
// Given a non-empty string s and an abbreviation abbr, return whether the string matches with the given abbreviation.
//
//
// A string such as "word" contains only the following valid abbreviations:
//
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//
//
// Notice that only the above abbreviations are valid abbreviations of the string "word". Any other string is not a valid abbreviation of "word".
//
// Note:
// Assume s contains only lowercase letters and abbr contains only lowercase letters and digits.
//
//
// Example 1:
//
// Given s = "internationalization", abbr = "i12iz4n":
//
// Return true.
//
//
//
// Example 2:
//
// Given s = "apple", abbr = "a2e":
//
// Return false.
//
//


class Solution {
public:
    bool validWordAbbreviation(string word, string abbr) {
        int pw = 0;
        int pa = 0;
        while (pa < abbr.size()) {
            if (abbr[pa] <= 'z' && abbr[pa] >= 'a') {
                if (pw >= word.size()) return false;
                if (word[pw] != abbr[pa]) return false;
                pw++;
                pa++;
                continue;
            }
            string num = "";
            while (abbr[pa] <= '9' && abbr[pa] >= '0') {
                num += abbr[pa];
                pa++;
            }
            int n = stoi(num);
            if (num[0] == '0') return false;
            pw += n;
            if (pw > word.size()) return false;
        }
        return pw == word.size();
    }
};
