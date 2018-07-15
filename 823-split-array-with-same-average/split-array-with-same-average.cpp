// In a given integer array A, we must move every element of A to either list B or list C. (B and C initially start empty.)
//
// Return true if and only if after such a move, it is possible that the average value of B is equal to the average value of C, and B and C are both non-empty.
//
//
// Example :
// Input: 
// [1,2,3,4,5,6,7,8]
// Output: true
// Explanation: We can split the array into [1,4,5,8] and [2,3,6,7], and both of them have the average of 4.5.
//
//
// Note:
//
//
// 	The length of A will be in the range [1, 30].
// 	A[i] will be in the range of [0, 10000].
//
//
//  


class Solution {
public:
    bool splitArraySameAverage(vector<int>& A) {
        int len=A.size();
        int sum=0;
        for (int i:A) sum+=i;
        vector<vector<vector<bool> > > dp(len, vector<vector<bool>>(len+1, vector<bool>(sum+1, false)));
        double avg=((double)sum)/((double)len);
        for (int i=0;i<len;i++) dp[i][0][0] = true;
        for (int i=1;i<len;i++) {
            for (int n=1;n<=i;n++) {
                for (int s=0;s<=sum;s++) {
                    bool a=dp[i-1][n][s];
                    bool b;
                    if (s-A[i-1] < 0) b=false;
                    else b=dp[i-1][n-1][s-A[i-1]];
                    bool r = a || b;
                    if (r) {
                        double ca = ((double)s)/((double)n);
                        if (abs(avg-ca) < 0.0001)
                            return true;
                    }
                    dp[i][n][s] = r;
                }
            }
        }
        return false;
    }
};
