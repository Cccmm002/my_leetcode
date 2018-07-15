// Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
// Example 1:
//
//
// Input:
// [
//  [ 1, 2, 3 ],
//  [ 4, 5, 6 ],
//  [ 7, 8, 9 ]
// ]
// Output: [1,2,3,6,9,8,7,4,5]
//
//
// Example 2:
//
// Input:
// [
//   [1, 2, 3, 4],
//   [5, 6, 7, 8],
//   [9,10,11,12]
// ]
// Output: [1,2,3,4,8,12,11,10,9,5,6,7]
//


class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> res;
        int height = matrix.size();
        if (height == 0) return res;
        int width = matrix[0].size();
        int status = 0; // 0: go_right; 1: go_down; 2: go_left; 3: go_up
        //int limits[4] = {width - 1, height - 1, 0, 0};
        int left = 0, right = width - 1;
        int up = 0, down = height - 1;
        //int next_dir[4] = {1, 2, 3, 0};
        int dirs[4][2] = {{1, 0}, {0, 1}, {-1, 0}, {0, -1}}; // x, y
        int x = 0, y = 0;
        while (true) {
            res.push_back(matrix[y][x]);
            int nx = x + dirs[status][0];
            int ny = y + dirs[status][1];
            if (status == 0 && nx > right) {
                nx = x; ny = y + 1;
                if (ny > down) break;
                status = 1;
                up++;
            }
            else if (status == 1 && ny > down) {
                nx = x - 1; ny = y;
                if (nx < left) break;
                status = 2;
                right--;
            }
            else if (status == 2 && nx < left) {
                nx = x; ny = y - 1;
                if (ny < up) break;
                status = 3;
                down--;
            }
            else if (status == 3 && ny < up) {
                nx = x + 1; ny = y;
                if (nx > right) break;
                status = 0;
                left++;
            }
            x = nx; y = ny;
        }
        return res;
    }
};
