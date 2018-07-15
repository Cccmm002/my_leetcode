// We partition a row of numbers A into at most K adjacent (non-empty) groups, then our score is the sum of the average of each group. What is the largest score we can achieve?
//
// Note that our partition must use every number in A, and that scores are not necessarily integers.
//
//
// Example:
// Input: 
// A = [9,1,2,3,9]
// K = 3
// Output: 20
// Explanation: 
// The best choice is to partition A into [9], [1, 2, 3], [9]. The answer is 9 + (1 + 2 + 3) / 3 + 9 = 20.
// We could have also partitioned A into [9, 1], [2], [3, 9], for example.
// That partition would lead to a score of 5 + 2 + 6 = 13, which is worse.
//
//
//  
//
// Note: 
//
//
// 	1 <= A.length <= 100.
// 	1 <= A[i] <= 10000.
// 	1 <= K <= A.length.
// 	Answers within 10^-6 of the correct answer will be accepted as correct.
//
//


class Solution {
public:
    double largestSumOfAverages(vector<int>& A, int KK) {
        int n = A.size();
        vector<int> presum(n + 1, 0);
        for (int i = 0; i < n; i++) presum[i + 1] = presum[i] + A[i];
        vector<vector<double>> dp(n + 1, vector<double>(KK + 1, 0));
        for (int i = 1; i <= n; i++) dp[i][0] = -INT_MAX;
        for (int k = 1; k <= KK; k++) {
            for (int i = 1; i <= n; i++) {
                for (int p = 1; p <= i; p++) {
                    double avg = double(presum[i] - presum[i - p])/double(p);
                    //double nd = dp[i - p][k - 1] + avg;
                    //if (nd > dp[i][k]) cout<<i<<" "<<k<<": "<<p<<endl;
                    dp[i][k] = max(dp[i][k], dp[i - p][k - 1] + avg);
                }
            }
        }
        return dp[n][KK];
    }
};
