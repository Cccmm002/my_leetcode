// Write a function to generate the generalized abbreviations of a word. 
//
// Note: The order of the output does not matter.
//
// Example:
//
//
// Input: "word"
// Output:
// ["word", "1ord", "w1rd", "wo1d", "wor1", "2rd", "w2d", "wo2", "1o1d", "1or1", "w1r1", "1o2", "2r1", "3d", "w3", "4"]
//
//
//  
//


class Solution {
private:
    unordered_map<string, unordered_set<string>> memory;
    
    unordered_set<string> calc(string word) {
        int len = word.size();
        unordered_set<string> res;
        if (len == 0) {
            res.insert("");
            return res;
        }
        if (len == 1) {
            res.insert("1");
            res.insert(word);
            return res;
        }
        if (memory.find(word) != memory.end()) return memory[word];
        res.insert(word);
        for (int i = 0; i < len; i++) {
            string left = word.substr(0, i);
            string right = word.substr(i + 1, len - i);
            unordered_set<string> leftSet = calc(left);
            unordered_set<string> rightSet = calc(right);
            for (string lw : leftSet) {
                for (string rw : rightSet) {
                    //cout<<left<<" "<<right<<" "<<lw<<" "<<rw<<endl;
                    int pl = lw.size() - 1;
                    while (pl >= 0 && lw[pl] <= '9' && lw[pl] >= '0') pl--;
                    int pr = 0;
                    while (pr < rw.size() && rw[pr] >= '0' && rw[pr] <= '9') pr++;
                    int nl = (pl + 1 >= lw.size()) ? 0 : stoi(lw.substr(pl + 1, lw.size() - pl - 1));
                    int nr = (pr <= 0) ? 0 : stoi(rw.substr(0, pr));
                    string sl = lw.substr(0, pl + 1);
                    string sr = rw.substr(pr, rw.size() - pr);
                    int middle = nl + nr + 1;
                    string s = sl + to_string(middle) + sr;
                    res.insert(s);
                }
            }
        }
        memory[word] = res;
        return res;
    }
public:
    vector<string> generateAbbreviations(string word) {
        vector<string> res;
        unordered_set<string> s = calc(word);
        for (string st : s) {
            //if (st == "") continue;
            res.push_back(st);
        }
        return res;
    }
};
