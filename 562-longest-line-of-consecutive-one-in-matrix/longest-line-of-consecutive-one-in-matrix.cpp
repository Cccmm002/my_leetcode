// Given a 01 matrix M, find the longest line of consecutive one in the matrix. The line could be horizontal, vertical, diagonal or anti-diagonal.
//
// Example:
//
// Input:
// [[0,1,1,0],
//  [0,1,1,0],
//  [0,0,0,1]]
// Output: 3
//
//
//
//
// Hint:
// The number of elements in the given matrix will not exceed 10,000.
//


class Solution {
public:
    int longestLine(vector<vector<int>>& M) {
        int height = M.size();
        if (height == 0) return 0;
        int width = M[0].size();
        vector<vector<vector<int>>> dp(height, vector<vector<int>>(width, vector<int>(4, 0)));
        int result = 0;
        for (int row = 0; row < height; ++row) {
            for (int col = 0; col < width; ++col) {
                if (M[row][col] == 0) continue;
                dp[row][col][0] = col > 0 ? dp[row][col - 1][0] + 1 : 1;   // left
                dp[row][col][1] = row > 0 ? dp[row - 1][col][1] + 1 : 1;   // up
                dp[row][col][2] = (col > 0 && row > 0) ? dp[row - 1][col - 1][2] + 1 : 1;   // upper left
                dp[row][col][3] = (row > 0 && col < width - 1) ? dp[row - 1][col + 1][3] + 1 : 1;   // upper right
                int current = max(max(dp[row][col][0], dp[row][col][1]), max(dp[row][col][2], dp[row][col][3]));
                result = max(result, current);
            }
        }
        return result;
    }
};
