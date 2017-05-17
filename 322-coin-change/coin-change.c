// You are given coins of different denominations and a total amount of money amount. Write a function to compute the fewest number of coins that you need to make up that amount. If that amount of money cannot be made up by any combination of the coins, return -1.
//
//
//
// Example 1:
// coins = [1, 2, 5], amount = 11
// return 3 (11 = 5 + 5 + 1)
//
//
//
// Example 2:
// coins = [2], amount = 3
// return -1.
//
//
//
// Note:
// You may assume that you have an infinite number of each kind of coin.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


int coinChange(int* coins, int coinsSize, int amount) {
    int *dp=(int*)malloc(sizeof(int)*(amount+1));
    dp[0]=0;
    for(int i=1;i<=amount;i++) {
        int min=-1;
        for(int j=0;j<coinsSize;j++) {
            if(i<coins[j]) continue;
            if(dp[i-coins[j]]==-1) continue;
            int r=dp[i-coins[j]]+1;
            if(min==-1)
                min=r;
            else
                min=min>r?r:min;
        }
        dp[i]=min;
    }
    int res=dp[amount];
    free(dp);
    return res;
}
