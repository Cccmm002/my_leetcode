//
// In English, we have a concept called root, which can be followed by some other words to form another longer word - let's call this word successor. For example, the root an, followed by other, which can form another word another.
//
//
//
//
// Now, given a dictionary consisting of many roots and a sentence. You need to replace all the successor in the sentence with the root forming it. If a successor has many roots can form it, replace it with the root with the shortest length.
//
//
//
// You need to output the sentence after the replacement.
//
//
//
// Example 1:
//
// Input: dict = ["cat", "bat", "rat"]
// sentence = "the cattle was rattled by the battery"
// Output: "the cat was rat by the bat"
//
//
//
//
// Note:
//
// The input will only have lower-case letters.
//  1 <= dict words number <= 1000 
//  1 <= sentence words number <= 1000  
//  1 <= root length <= 100 
//  1 <= sentence words length <= 1000 
//
//


class Solution {
private:
    vector<string> split(const string &s, char delim) {
        stringstream ss(s);
        string item;
        vector<string> tokens;
        while (getline(ss, item, delim)) {
            tokens.push_back(item);
        }
        return tokens;
    }

public:
    string replaceWords(vector<string>& dict, string sentence) {
        unordered_set<string> us;
        for (int i = 0; i < dict.size(); i++) us.insert(dict[i]);
        vector<string> tokens = split(sentence, ' ');
        int n = tokens.size();
        string res = "";
        for (int i = 0; i < n; i++) {
            int len = tokens[i].size();
            string put = tokens[i];
            for (int j = 0; j < len; j++) {
                string cur = put.substr(0, j + 1);
                if (us.find(cur) != us.end()) {
                    put = cur;
                    break;
                }
            }
            res += put + " ";
        }
        return res.substr(0, res.size() - 1);
    }
};
