// In the computer world, use restricted resource you have to generate maximum benefit is what we always want to pursue.
// For now, suppose you are a dominator of m 0s and n 1s respectively. On the other hand, there is an array with strings consisting of only 0s and 1s.
//
//
// Now your task is to find the maximum number of strings that you can form with given m 0s and n 1s. Each 0 and 1 can be used at most once.
//
//
//
// Note:
//
// The given numbers of 0s and 1s will both not exceed 100
// The size of given string array won't exceed 600.
//
//
//
// Example 1:
//
// Input: Array = {"10", "0001", "111001", "1", "0"}, m = 5, n = 3
// Output: 4
//
// Explanation: This are totally 4 strings can be formed by the using of 5 0s and 3 1s, which are “10,”0001”,”1”,”0”
//
//
//
// Example 2:
//
// Input: Array = {"10", "0", "1"}, m = 1, n = 1
// Output: 2
//
// Explanation: You could form "10", but then you'd have nothing left. Better form "0" and "1".


class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len = strs.size();
        if (len == 0) return 0;
        vector<int> zeros(len, 0);
        vector<int> ones(len, 0);
        for (int i = 0; i < len; i++) {
            for (char c : strs[i]) {
                if (c == '1') ones[i]++;
                else zeros[i]++;
            }
        }
        vector<vector<int>> arr(m + 1);
        for (int i = 0; i <= m; i++) {
            vector<int> v(n + 1, 0);
            arr[i] = v;
        }
        for (int i = zeros[0]; i <= m; i++) {
            for (int j = ones[0]; j <= n; j++) 
                arr[i][j] = 1;
        }
        for (int p = 1; p < len; p++) {
            for (int i = m; i >= 0; i--) {
                int z = i - zeros[p];
                if (z < 0) continue;
                for (int j = n; j >= 0; j--) {
                    int o = j - ones[p];
                    if (o < 0) continue;
                    arr[i][j] = max(arr[i][j], arr[z][o] + 1);
                }
            }
        }
        return arr[m][n];
    }
};
