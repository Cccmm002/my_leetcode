// Given a list of strings, you need to find the longest uncommon subsequence among them. The longest uncommon subsequence is defined as the longest subsequence of one of these strings and this subsequence should not be any subsequence of the other strings.
//
//
//
// A subsequence is a sequence that can be derived from one sequence by deleting some characters without changing the order of the remaining elements. Trivially, any string is a subsequence of itself and an empty string is a subsequence of any string.
//
//
//
// The input will be a list of strings, and the output needs to be the length of the longest uncommon subsequence. If the longest uncommon subsequence doesn't exist, return -1.
//
//
// Example 1:
//
// Input: "aba", "cdc", "eae"
// Output: 3
//
//
//
// Note:
//
// All the given strings' lengths will not exceed 10.
// The length of the given list will be in the range of [2, 50].


class Solution {
private:
    bool isSub(string a, string b) {
        int la = a.size();
        int lb = b.size();
        int i = 0, j = 0;
        while (i < lb && j < la) {
            if (a[j] == b[i]) {
                i++;
                j++;
            }
            else {
                i++;
            }
        }
        return j == la;
    }
    
public:
    int findLUSlength(vector<string>& strs) {
        int res = -1;
        int n = strs.size();
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (i == j) continue;
                if (isSub(strs[i], strs[j])) {
                    flag = false;
                    break;
                }
            }
            if (flag) res = max(res, (int)strs[i].size());
        }
        return res;
    }
};
