// You have a number of envelopes with widths and heights given as a pair of integers (w, h). One envelope can fit into another if and only if both the width and height of one envelope is greater than the width and height of the other envelope.
//
//
// What is the maximum number of envelopes can you Russian doll? (put one inside other)
//
//
// Example:
// Given envelopes = [[5,4],[6,4],[6,7],[2,3]], the maximum number of envelopes you can Russian doll is 3 ([2,3] => [5,4] => [6,7]).
//


class Solution {
public:
    int maxEnvelopes(vector<pair<int, int>>& envelopes) {
        int n = envelopes.size();
        if (n <= 0) return 0;
        sort(envelopes.begin(), envelopes.end());
        vector<int> arr(n, 1);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i].first > envelopes[j].first && envelopes[i].second > envelopes[j].second)
                    arr[i] = max(arr[i], arr[j] + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; i++) res = max(res, arr[i]);
        return res;
    }
};
