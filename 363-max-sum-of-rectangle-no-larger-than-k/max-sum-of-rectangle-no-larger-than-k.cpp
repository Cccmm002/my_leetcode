// Given a non-empty 2D matrix matrix and an integer k, find the max sum of a rectangle in the matrix such that its sum is no larger than k.
//
// Example:
// Given matrix = [
//   [1,  0, 1],
//   [0, -2, 3]
// ]
// k = 2
//
//
//
// The answer is 2. Because the sum of rectangle [[0, 1], [-2, 3]] is 2 and 2 is the max number no larger than k (k = 2).
//
// Note:
//
// The rectangle inside the matrix must have an area > 0.
// What if the number of rows is much larger than the number of columns?
//
//
//
// Credits:Special thanks to @fujiaozhu for adding this problem and creating all test cases.


class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int height = matrix.size();
        int width = matrix[0].size();
        vector<vector<int>> psum(height);
        for (int i = 0; i < height; i++) {
            vector<int> v(width, 0);
            psum[i] = v;
        }
        int res = INT_MIN;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                psum[i][j] = matrix[i][j];
                if (i - 1 >= 0) psum[i][j] += psum[i - 1][j];
                if (j - 1 >= 0) psum[i][j] += psum[i][j - 1];
                if (i - 1 >= 0 && j - 1 >= 0) psum[i][j] -= psum[i - 1][j - 1];
                
                for (int a = 0; a <= i; a++) {
                    for (int b = 0; b <= j; b++) {
                        int cur = psum[i][j];
                        if (a - 1 >= 0) cur -= psum[a - 1][j];
                        if (b - 1 >= 0) cur -= psum[i][b - 1];
                        if (a - 1 >= 0 && b - 1 >= 0) cur += psum[a - 1][b - 1];
                        if (cur > k) continue;
                        res = max(res, cur);
                    }
                }
            }
        }
        return res;
    }
};
