// Given two sparse matrices A and B, return the result of AB.
//
// You may assume that A's column number is equal to B's row number.
//
// Example:
//
//
// Input:
//
// A = [
//   [ 1, 0, 0],
//   [-1, 0, 3]
// ]
//
// B = [
//   [ 7, 0, 0 ],
//   [ 0, 0, 0 ],
//   [ 0, 0, 1 ]
// ]
//
// Output:
//
//      |  1 0 0 |   | 7 0 0 |   |  7 0 0 |
// AB = | -1 0 3 | x | 0 0 0 | = | -7 0 3 |
//                   | 0 0 1 |
//
//


class Solution {
public:
    vector<vector<int>> multiply(vector<vector<int>>& A, vector<vector<int>>& B) {
        int height = A.size();
        int width = B[0].size();
        int k_limit = B.size();
        vector<vector<int>> res(height);
        for (int i = 0; i < height; i++) {
            vector<int> v(width, 0);
            res[i] = v;
        }
        for (int y = 0; y < height; y++) {
            for (int k = 0; k < k_limit; k++) {
                if (A[y][k] == 0) continue;
                for (int x = 0; x < width; x++) {
                    res[y][x] += A[y][k] * B[k][x];
                }
            }
        }
        return res;
    }
};
