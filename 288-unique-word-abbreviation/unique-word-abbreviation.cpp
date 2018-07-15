// An abbreviation of a word follows the form <first letter><number><last letter>. Below are some examples of word abbreviations:
//
//
// a) it                      --> it    (no abbreviation)
//
//      1
//      ↓
// b) d|o|g                   --> d1g
//
//               1    1  1
//      1---5----0----5--8
//      ↓   ↓    ↓    ↓  ↓    
// c) i|nternationalizatio|n  --> i18n
//
//               1
//      1---5----0
//      ↓   ↓    ↓
// d) l|ocalizatio|n          --> l10n
//
//
// Assume you have a dictionary and given a word, find whether its abbreviation is unique in the dictionary. A word's abbreviation is unique if no other word from the dictionary has the same abbreviation.
//
// Example:
//
//
// Given dictionary = [ "deer", "door", "cake", "card" ]
//
// isUnique("dear") -> false
// isUnique("cart") -> true
// isUnique("cane") -> false
// isUnique("make") -> true
//
//


class ValidWordAbbr {
private:
    unordered_map<string, int> ump;
    unordered_set<string> dict;
    
    string abbr(string word) {
        int len = word.size();
        if (len <= 2) return word;
        string res = "";
        res += word[0];
        res += to_string(len - 2);
        res += word[len - 1];
        return res;
    }
    
public:
    ValidWordAbbr(vector<string> dictionary) {
        for (string word : dictionary) {
            if (dict.find(word) != dict.end()) continue;
            dict.insert(word);
            string ab = abbr(word);
            if (ump.find(ab) != ump.end()) {
                ump[ab]++;
            }
            else {
                ump[ab] = 1;
            }
        }
    }
    
    bool isUnique(string word) {
        if (dict.find(word) != dict.end()) {
            return ump[abbr(word)] <= 1;
        }
        else {
            return ump[abbr(word)] == 0;
        }
    }
};

/**
 * Your ValidWordAbbr object will be instantiated and called as such:
 * ValidWordAbbr obj = new ValidWordAbbr(dictionary);
 * bool param_1 = obj.isUnique(word);
 */
