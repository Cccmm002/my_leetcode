// There is a new alien language which uses the latin alphabet. 
// However, the order among letters are unknown to you. 
// You receive a list of non-empty words from the dictionary, where words are sorted lexicographically by the rules of this new language.
// Derive the order of letters in this language.
//
//
//
// Example 1:
// Given the following words in dictionary,
//
// [
//   "wrt",
//   "wrf",
//   "er",
//   "ett",
//   "rftt"
// ]
//
//
//
// The correct order is: "wertf".
//
//
// Example 2:
// Given the following words in dictionary,
//
// [
//   "z",
//   "x"
// ]
//
//
//
// The correct order is: "zx".
//
//
// Example 3:
// Given the following words in dictionary,
//
// [
//   "z",
//   "x",
//   "z"
// ]
//
//
//
// The order is invalid, so return "".
//
// Note:
//
// You may assume all letters are in lowercase.
// You may assume that if a is a prefix of b, then a must appear before b in the given dictionary.
// If the order is invalid, return an empty string.
// There may be multiple valid order of letters, return any one of them is fine.


class Solution {
private:
    unordered_map<char, unordered_set<char>> next;
    unordered_map<char, unordered_set<char>> coming;

    pair<char, char> getOrder(string a, string b) {
        int lena = a.size();
        int lenb = b.size();
        for (int i = 0; i < min(lena, lenb); i++) {
            if (a[i] != b[i]) {
                return make_pair(a[i], b[i]);
            }
        }
        return make_pair('\0', '\0');
    }
    
    void putChars(string s) {
        int len = s.size();
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (next.find(c) == next.end()) {
                unordered_set<char> uc;
                next[c] = uc;
            }
            if (coming.find(c) == coming.end()) {
                unordered_set<char> uc;
                coming[c] = uc;
            }
        }
    }
    
public:
    string alienOrder(vector<string>& words) {
        int len = words.size();
        if (len == 0) return "";
        if (len == 1) return words[0];
        for (int i = 0; i < len - 1; i++) {
            putChars(words[i]);
            putChars(words[i + 1]);
            if (words[i] == words[i + 1]) continue;
            pair<char, char> p = getOrder(words[i], words[i + 1]);
            if (p.first == '\0') continue;
            next[p.first].insert(p.second);
            coming[p.second].insert(p.first);
        }
        
        string res = "";
        unordered_set<char> s;
        auto it_noincoming = coming.begin();
        while (it_noincoming != coming.end()) {
            if (it_noincoming->second.size() == 0) {
                s.insert(it_noincoming->first);
            }
            it_noincoming++;
        }
        while (!s.empty()) {
            auto it = s.begin();
            char c = *it;
            res += c;
            s.erase(it);
            auto sit = next[c].begin();
            while (sit != next[c].end()) {
                char nc = *sit;
                coming[nc].erase(c);
                if (coming[nc].size() == 0) s.insert(nc);
                sit++;
            }
        }
        bool exist = true;
        auto ait = coming.begin();
        while (ait != coming.end()) {
            if (ait->second.size() != 0) {
                exist = false;
                break;
            }
            ait++;
        }
        if (exist) return res;
        else return "";
    }
};
