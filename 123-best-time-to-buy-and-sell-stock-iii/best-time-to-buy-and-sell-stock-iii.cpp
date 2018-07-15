// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note: You may not engage in multiple transactions at the same time (i.e., you must sell the stock before you buy again).
//
// Example 1:
//
//
// Input: [3,3,5,0,0,3,1,4]
// Output: 6
// Explanation: Buy on day 4 (price = 0) and sell on day 6 (price = 3), profit = 3-0 = 3.
//              Then buy on day 7 (price = 1) and sell on day 8 (price = 4), profit = 4-1 = 3.
//
// Example 2:
//
//
// Input: [1,2,3,4,5]
// Output: 4
// Explanation: Buy on day 1 (price = 1) and sell on day 5 (price = 5), profit = 5-1 = 4.
//              Note that you cannot buy on day 1, buy on day 2 and sell them later, as you are
//              engaging multiple transactions at the same time. You must sell before buying again.
//
//
// Example 3:
//
//
// Input: [7,6,4,3,1]
// Output: 0
// Explanation: In this case, no transaction is done, i.e. max profit = 0.
//


class Solution {
private:
    int _maxProfit(int k, vector<int>& prices) {
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
    
public:
    int maxProfit(vector<int>& prices) {
        return _maxProfit(2, prices);
    }
};
