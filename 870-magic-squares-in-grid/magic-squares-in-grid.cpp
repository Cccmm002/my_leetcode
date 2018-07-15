// A 3 x 3 magic square is a 3 x 3 grid filled with distinct numbers from 1 to 9 such that each row, column, and both diagonals all have the same sum.
//
// Given an grid of integers, how many 3 x 3 "magic square" subgrids are there?  (Each subgrid is contiguous).
//
//  
//
// Example 1:
//
//
// Input: [[4,3,8,4],
//         [9,5,1,9],
//         [2,7,6,2]]
// Output: 1
// Explanation: 
// The following subgrid is a 3 x 3 magic square:
// 438
// 951
// 276
//
// while this one is not:
// 384
// 519
// 762
//
// In total, there is only one magic square inside the given grid.
//
//
// Note:
//
//
// 	1 <= grid.length <= 10
// 	1 <= grid[0].length <= 10
// 	0 <= grid[i][j] <= 15
//
//


class Solution {
private:
    bool magic(vector<vector<int>>& grid, int row, int col) {
        vector<bool> b(9, false);
        for (int i=0;i<3;i++) {
            for (int j=0;j<3;j++) {
                int cur = grid[row+i][col+j];
                if (cur < 1 || cur > 9) return false;
                if (b[cur - 1]) return false;
                b[cur - 1] = true;
            }
        }
        for (int i=0;i<9;i++) {
            if (!b[i]) return false;
        }
        
        int sum = grid[row][col] + grid[row + 1][col] + grid[row + 2][col];
        for (int r = row; r < row + 3; r++) {
            if (sum != grid[r][col] + grid[r][col + 1] + grid[r][col + 2])
                return false;
        }
        for (int c = col; c < col + 3; c++) {
            if (sum != grid[row][c] + grid[row + 1][c] + grid[row + 2][c])
                return false;
        }
        if (sum != grid[row][col] + grid[row + 1][col + 1] + grid[row + 2][col + 2])
            return false;
        if (sum != grid[row][col + 2] + grid[row + 1][col + 1] + grid[row + 2][col])
            return false;
        return true;
    }
    
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int height = grid.size();
        if (height < 3)
            return 0;
        int width = grid[0].size();
        if (width < 3)
            return 0;
        int res = 0;
        for (int i = 0; i < height - 2; i++) {
            for (int j = 0; j < width - 2; j++) {
                if (magic(grid, i, j)) {
                    //if (i==0&&j==0&&width==3&&height == 3) continue;
                    res += 1;
                }
            }
        }
        return res;
    }
};
