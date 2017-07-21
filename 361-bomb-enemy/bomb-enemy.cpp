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
        vector<vector<int>> head_row(height);
        vector<vector<int>> head_col(height);
        for (int i = 0; i < height; ++i) {
            vector<int> v1(width);
            vector<int> v2(width);
            head_row[i] = v1; head_col[i] = v2;
            for (int j = 0; j < width; ++j) {
                head_row[i][j] = 0; head_col[i][j] = 0;
                if (grid[i][j] != 'W') {
                    if (i != 0) {
                        head_row[i][j] += head_row[i-1][j];
                        if (grid[i-1][j] == 'E') head_row[i][j]++;
                    }
                    if (j != 0) {
                        head_col[i][j] += head_col[i][j-1];
                        if (grid[i][j-1] == 'E') head_col[i][j]++;
                    }
                }
            }
        }
        vector<vector<int>> tail_row(height);
        vector<vector<int>> tail_col(height);
        for (int i = height - 1; i >= 0; i--) {
            vector<int> v1(width);
            vector<int> v2(width);
            tail_row[i] = v1; tail_col[i] = v2;
            for (int j = width - 1; j >= 0; j--) {
                tail_row[i][j] = 0; tail_col[i][j] = 0;
                if (grid[i][j] != 'W') {
                    if (i != height - 1) {
                        tail_row[i][j] += tail_row[i+1][j];
                        if (grid[i+1][j] == 'E') tail_row[i][j]++;
                    }
                    if (j != width - 1) {
                        tail_col[i][j] += tail_col[i][j+1];
                        if (grid[i][j+1] == 'E') tail_col[i][j]++;
                    }
                }
            }
        }
        int largest = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                //cout<<i<<" "<<j<<" "<<tail_col[i][j] << " " << head_col[i][j] << " " << tail_row[i][j] << " " << head_row[i][j]<<endl;
                if (grid[i][j] == '0') {
                    int cur = tail_col[i][j] + head_col[i][j] + tail_row[i][j] + head_row[i][j];
                    largest = max(largest, cur);
                }
            }
        }
        return largest;
    }
};
