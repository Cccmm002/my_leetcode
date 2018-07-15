// Given a 2D grid, each cell is either a wall 'W', an enemy 'E' or empty '0' (the number zero), return the maximum enemies you can kill using one bomb. The bomb kills all the enemies in the same row and column from the planted point until it hits the wall since the wall is too strong to be destroyed.
//  Note that you can only put the bomb at an empty cell. 
//
// Example:
//
// For the given grid
//
// 0 E 0 0
// E 0 W E
// 0 E 0 0
//
// return 3. (Placing a bomb at (1,1) kills 3 enemies)
//
//
//
// Credits:Special thanks to @memoryless for adding this problem and creating all test cases.


class Solution {
public:
    int maxKilledEnemies(vector<vector<char>>& grid) {
        int height = grid.size();
        if (height == 0) return 0;
        int width = grid[0].size();
        if (width == 0) return 0;
        
        vector<vector<int>> left(height, vector<int>(width, 0));
        vector<vector<int>> right(height, vector<int>(width, 0));
        vector<vector<int>> up(height, vector<int>(width, 0));
        vector<vector<int>> down(height, vector<int>(width, 0));
        
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 'W') {
                    left[i][j] = 0;
                    up[i][j] = 0;
                }
                else {
                    left[i][j] = grid[i][j] == 'E' ? 1 : 0;
                    up[i][j] = grid[i][j] == 'E' ? 1 : 0;
                    if (i > 0) left[i][j] += left[i - 1][j];
                    if (j > 0) up[i][j] += up[i][j - 1];
                }
            }
        }
        for (int i = height - 1; i >= 0; i--) {
            for (int j = width - 1; j >= 0; j--) {
                if (grid[i][j] == 'W') {
                    right[i][j] = 0;
                    down[i][j] = 0;
                }
                else {
                    right[i][j] = grid[i][j] == 'E' ? 1 : 0;
                    down[i][j] = grid[i][j] == 'E' ? 1 : 0;
                    if (i < height - 1) right[i][j] += right[i + 1][j];
                    if (j < width - 1) down[i][j] += down[i][j + 1];
                }
            }
        }
        int res = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 'W' || grid[i][j] == 'E')
                    continue;
                int cur = left[i][j] + right[i][j] + up[i][j] + down[i][j];
                res = max(res, cur);
            }
        }
        return res;
    }
};
