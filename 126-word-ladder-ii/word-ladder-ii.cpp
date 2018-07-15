// Given two words (beginWord and endWord), and a dictionary's word list, find all shortest transformation sequence(s) from beginWord to endWord, such that:
//
//
// 	Only one letter can be changed at a time
// 	Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//
//
// Note:
//
//
// 	Return an empty list if there is no such transformation sequence.
// 	All words have the same length.
// 	All words contain only lowercase alphabetic characters.
// 	You may assume no duplicates in the word list.
// 	You may assume beginWord and endWord are non-empty and are not the same.
//
//
// Example 1:
//
//
// Input:
// beginWord = "hit",
// endWord = "cog",
// wordList = ["hot","dot","dog","lot","log","cog"]
//
// Output:
// [
//   ["hit","hot","dot","dog","cog"],
//   ["hit","hot","lot","log","cog"]
// ]
//
//
// Example 2:
//
//
// Input:
// beginWord = "hit"
// endWord = "cog"
// wordList = ["hot","dot","dog","lot","log"]
//
// Output: []
//
// Explanation: The endWord "cog" is not in wordList, therefore no possible transformation.
//
//
//
//
//


void add_to_tree(map<string, vector<string>>& tree, 
              string word, 
              string neigh, 
              bool forward) {
    if (forward) tree[word].push_back(neigh);
    else         tree[neigh].push_back(word);

}

vector<vector<string>> construct_paths(map<string, 
                                       vector<string>>& tree, 
                                       string start, 
                                       string dest) {
    if (start == dest) {
        vector<string> res = {start};
        vector<vector<string>> arr = {res};
        return arr;
    }
    vector<vector<string>> result;

    for (auto succ: tree[start]) {
        for (auto path: construct_paths(tree, succ, dest)) {
            path.insert(path.begin(), start);
            result.push_back(path);
        }
    }
    return result;
}

bool bfs_levels(unordered_set<string>& now, 
                unordered_set<string>& oth, 
                bool& forward, 
                map<string, vector<string>>& tree, 
                unordered_set<string>& words_list,
                vector<char>& alphabet) {

    if (not now.size()) return false;
    if (now.size() > oth.size()){
        forward = not forward;
        return bfs_levels(oth, now, forward, tree, words_list, alphabet);
    }
    for (auto word: now) words_list.erase(word);
    for (auto word: oth) words_list.erase(word);
    
    bool done = false; unordered_set<string> next;

    for (string word: now) {
        for (int i = 0; i < word.size(); i++) {
            for (char c: alphabet) {
                auto neigh = word.substr(0, i) + c + word.substr(i+1);
                if (oth.count(neigh) > 0) {
                    done = true;
                    add_to_tree(tree, word, neigh, forward);
                }
                else {
                    if (not done and words_list.count(neigh) > 0) {
                        next.insert(neigh);
                        add_to_tree(tree, word, neigh, forward);
                    }
                }
            }
        }
    }
    forward = not forward;
    return done or bfs_levels(oth, next, forward, tree, words_list, alphabet);
}


class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, 
                                       string endWord, 
                                       unordered_set<string> &wordList) {

        vector<char> alphabet(26);
        std::iota(alphabet.begin(), alphabet.end(), 'a');
        unordered_set<string> now = {beginWord}, oth = {endWord};
        map<string, vector<string>> tree; bool forward = true;
        auto is_found = bfs_levels(now, oth, forward, tree, wordList, alphabet);
        return construct_paths(tree, beginWord, endWord);    
                                           
    }
};
