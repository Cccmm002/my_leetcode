// Given a non-empty array of numbers, a0, a1, a2, … , an-1, where 0 &le; ai < 231.
//
// Find the maximum result of ai XOR aj, where 0 &le; i, j &lt; n.
//
// Could you do this in O(n) runtime?
//
// Example:
//
// Input: [3, 10, 5, 25, 2, 8]
//
// Output: 28
//
// Explanation: The maximum result is 5 ^ 25 = 28.


class Solution {
public:
    int findMaximumXOR(vector<int>& nums) {
        int res = 0;
        int mask = 0;
        for (int i = 31; i >= 0; i--) {
            mask = mask | (1 << i);
            unordered_set<int> s;
            for (int n : nums) {
                s.insert(mask & n);
            }
            int tmp = res | (1 << i);
            for (int n : s) {
                if (s.find(n ^ tmp) != s.end()) {
                    res = tmp;
                    break;
                }
            }
        }
        return res;
    }
};
