//
// Given a string, find the length of the longest substring T that contains at most k distinct characters.
//
//
//
// For example,
//
// Given s = “eceba” and k = 2,
//
//
//
// T is "ece" which its length is 3.
//


class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        unordered_map<char, int> ump;
        int len = s.size();
        if (len == 0) return 0;
        int begin = 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            ump[c] = i;
            if (ump.size() > k) {
                auto it = ump.begin();
                int left = len;
                auto it_del = ump.begin();
                while (it != ump.end()) {
                    if (it->second < left) {
                        left = it->second;
                        it_del = it;
                    }
                    it++;
                }
                begin = left + 1;
                ump.erase(it_del);
            }
            res = max(res, i - begin + 1);
        }
        return res;
    }
};
