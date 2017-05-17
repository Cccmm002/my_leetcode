// Say you have an array for which the ith element is the price of a given stock on day i.
//
// Design an algorithm to find the maximum profit. You may complete as many transactions as you like (ie, buy one and sell one share of the stock multiple times). However, you may not engage in multiple transactions at the same time (ie, you must sell the stock before you buy again).


class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int size=prices.size();
        if(size==0) return 0;
        prices.push_back(0);
        int res=0;
        int beg=prices[0];
        int con=1;
        for(int i=1;i<size+1;i++) {
            if(prices[i]>=prices[i-1]){
                con++;
                continue;
            }
            else{
                if(con==1){
                    beg=prices[i];
                    continue;
                }
                else{
                    res+=prices[i-1]-beg;
                    beg=prices[i];
                    con=1;
                }
            }
        }
        return res;
    }
};
