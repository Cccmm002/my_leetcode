// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most k transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [2,4,1], k = 2
// Output: 2
// Explanation: Buy on day 1 (price = 2) and sell on day 2 (price = 4), profit = 4-2 = 2.
//
//
// Example 2:
//
//
// Input: [3,2,6,5,0,3], k = 2
// Output: 7
// Explanation: Buy on day 2 (price = 2) and sell on day 3 (price = 6), profit = 6-2 = 4.
//              Then buy on day 5 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//
//


class Solution {
public:
    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0; 
        if (k >= n/2) {
            int res = 0;
            for (int i = 1; i < n; i++) {
                if (prices[i] - prices[i - 1] > 0)
                    res += prices[i] - prices[i - 1];
            }
            return res;
        }
        vector<int> prev(n, 0);
        for (int t = 1; t <= k; t++) {
            vector<int> dp(n, 0);
            vector<int> prev_max(n, 0);
            prev_max[0] = prev[0] - prices[0];
            for (int p = 1; p < n; p++) prev_max[p] = max(prev_max[p - 1], prev[p] - prices[p]);
            for (int i = 1; i < n; i++) {
                int tmp = max(dp[i - 1], prev_max[i - 1] + prices[i]);
                dp[i] = max(dp[i], tmp);
            }
            prev = dp;
        }
        return prev[n - 1];
    }
};
