// Given a non-empty list of words, return the k most frequent elements.
// Your answer should be sorted by frequency from highest to lowest. If two words have the same frequency, then the word with the lower alphabetical order comes first.
//
// Example 1:
//
// Input: ["i", "love", "leetcode", "i", "love", "coding"], k = 2
// Output: ["i", "love"]
// Explanation: "i" and "love" are the two most frequent words.
//     Note that "i" comes before "love" due to a lower alphabetical order.
//
//
//
// Example 2:
//
// Input: ["the", "day", "is", "sunny", "the", "the", "the", "sunny", "is", "is"], k = 4
// Output: ["the", "is", "sunny", "day"]
// Explanation: "the", "is", "sunny" and "day" are the four most frequent words,
//     with the number of occurrence being 4, 3, 2 and 1 respectively.
//
//
//
// Note:
//
// You may assume k is always valid, 1 ≤ k ≤ number of unique elements.
// Input words contain only lowercase letters.
//
//
//
// Follow up:
//
// Try to solve it in O(n log k) time and O(n) extra space.
//
//


struct Word {
    string s;
    int freq;
    
    Word (string _s, int _f) : s(_s), freq(_f) {}
};

bool cmp (Word w1, Word w2) {
    if (w1.freq < w2.freq) return false;
    if (w1.freq > w2.freq) return true;
    else return w1.s < w2.s;
}

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> ump;
        for (string &w : words) {
            if (ump.count(w) == 0)
                ump[w] = 1;
            else
                ump[w] += 1;
        }
        priority_queue<Word, vector<Word>, std::function<bool(Word, Word)>> pq(cmp);
        auto it = ump.begin();
        while (it != ump.end()) {
            Word cur(it->first, it->second);
            pq.push(cur);
            if (pq.size() > k)
                pq.pop();
            it++;
        }
        vector<string> res(k);
        for (int i = k - 1; i >= 0; i--) {
            Word cur = pq.top();
            pq.pop();
            res[i] = cur.s;
        }
        return res;
    }
};
