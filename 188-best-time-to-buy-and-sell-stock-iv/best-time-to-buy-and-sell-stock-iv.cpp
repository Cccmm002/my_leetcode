// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 0) return 0;
        if (k >= n/2) {
            int maxPro = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] > prices[i - 1])
                    maxPro += prices[i] - prices[i - 1];
            }
            return maxPro;
        }
        int **f = new int*[k + 1];
        for (int i = 0; i < k + 1; i++) {
            f[i] = new int[n];
            for (int j = 0; j < n; j++)
                f[i][j] = 0;
        }
        for (int m = 1; m <= k; m++) {
            for (int i = 1; i < n; i++) {
                int cur = f[m][i - 1];
                for (int p = 0; p < i; p++) {
                    int c = prices[i] - prices[p];
                    if (p > 0) c += f[m - 1][p - 1];
                    if (c > cur) cur = c;
                }
                f[m][i] = cur;
            }
        }
        return f[k][n - 1];
    }
};
