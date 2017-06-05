// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete at most two transactions.
//
// Note:
// You may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len <= 0) return 0;
        vector<int> left(len, 0);
        vector<int> right(len, 0);
        
        int leftMin = prices[0];
        int cur_largest = 0;
        for (int i = 1; i < len; i++) {
            if (prices[i] < leftMin)
                leftMin = prices[i];
            else
                cur_largest = max(cur_largest, prices[i] - leftMin);
            left[i] = cur_largest;
        }
        
        int res = left[len - 1];
        
        int rightMax = prices[len - 1];
        cur_largest = 0;
        for (int i = len - 2; i >= 0; i--) {
            if (prices[i] > rightMax)
                rightMax = prices[i];
            else
                cur_largest = max(cur_largest, rightMax - prices[i]);
            right[i] = cur_largest;
            res = max(res, left[i] + right[i]);
        }
        return res;
    }
};
