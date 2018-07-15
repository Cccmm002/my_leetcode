// Given a positive integer n, find the least number of perfect square numbers (for example, 1, 4, 9, 16, ...) which sum to n.
//
// Example 1:
//
//
// Input: n = 12
// Output: 3 
// Explanation: 12 = 4 + 4 + 4.
//
// Example 2:
//
//
// Input: n = 13
// Output: 2
// Explanation: 13 = 4 + 9.
//


class Solution {
public:
    int numSquares(int n) {
        vector<int> arr(n + 1, INT_MAX);
        arr[0] = 0; arr[1] = 1;
        for (int i = 2; i <= n; i++) {
            int s = sqrt(i);
            for (int k = 1; k <= s; k++) {
                arr[i] = min(arr[i], arr[i - k*k] + 1);
            }
        }
        return arr[n];
    }
};
