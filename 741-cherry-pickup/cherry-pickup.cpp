//
// In a N x N grid representing a field of cherries, each cell is one of three possible integers.
//
// 0 means the cell is empty, so you can pass through;
// 1 means the cell contains a cherry, that you can pick up and pass through;
// -1 means the cell contains a thorn that blocks your way.
//
// Your task is to collect maximum number of cherries possible by following the rules below:
//
// Starting at the position (0, 0) and reaching (N-1, N-1) by moving right or down through valid path cells (cells with value 0 or 1);
// After reaching (N-1, N-1), returning to (0, 0) by moving left or up through valid path cells;
// When passing through a path cell containing a cherry, you pick it up and the cell becomes an empty cell (0);
// If there is no valid path between (0, 0) and (N-1, N-1), then no cherries can be collected.
//
//
// Example 1:
//
// Input: grid =
// [[0, 1, -1],
//  [1, 0, -1],
//  [1, 1,  1]]
// Output: 5
// Explanation: 
// The player started at (0, 0) and went down, down, right right to reach (2, 2).
// 4 cherries were picked up during this single trip, and the matrix becomes [[0,1,-1],[0,0,-1],[0,0,0]].
// Then, the player went left, up, up, left to return home, picking up one more cherry.
// The total number of cherries picked up is 5, and this is the maximum possible.
//
//
//
// Note:
// grid is an N by N 2D array, with 1 <= N <= 50.
// Each grid[i][j] is an integer in the set {-1, 0, 1}.
// It is guaranteed that grid[0][0] and grid[N-1][N-1] are not -1.
//


class Solution {
public:
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> arr(n, vector<vector<int>> (n, vector<int> (n, INT_MIN)));
        arr[0][0][0] = grid[0][0];
        for (int a = 0; a < n; a++) {
            for (int b = 0; b < n; b++) {
                for (int c = 0; c < n; c++) {
                    if (a + b == 0) continue;
                    // if (a == c) continue; // ????
                    int d = a + b - c;
                    if (d < 0 || d >= n) continue;
                    if (grid[a][b] == -1 || grid[c][d] == -1) {
                        arr[a][b][c] = INT_MIN;
                        continue;
                    }
                    arr[a][b][c] = a >= 1?arr[a - 1][b][c]:INT_MIN;
                    if (a >= 1 && c >= 1) arr[a][b][c] = max(arr[a][b][c], arr[a - 1][b][c - 1]);
                    if (b >= 1 && c >= 1) arr[a][b][c] = max(arr[a][b][c], arr[a][b - 1][c - 1]);
                    if (b >= 1) arr[a][b][c] = max(arr[a][b][c], arr[a][b - 1][c]);
                    if (a == c) arr[a][b][c] += grid[a][b];
                    else arr[a][b][c] += grid[a][b] + grid[c][d];
                }
            }
        }
        int res = arr[n - 1][n - 1][n - 1];
        if (res < 0) return 0;
        else return res;
    }
};
