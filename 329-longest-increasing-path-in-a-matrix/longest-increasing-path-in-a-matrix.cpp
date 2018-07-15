// Given an integer matrix, find the length of the longest increasing path.
//
// From each cell, you can either move to four directions: left, right, up or down. You may NOT move diagonally or move outside of the boundary (i.e. wrap-around is not allowed).
//
// Example 1:
//
//
// Input: nums = 
// [
//   [9,9,4],
//   [6,6,8],
//   [2,1,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [1, 2, 6, 9].
//
//
// Example 2:
//
//
// Input: nums = 
// [
//   [3,4,5],
//   [3,2,6],
//   [2,2,1]
// ] 
// Output: 4 
// Explanation: The longest increasing path is [3, 4, 5, 6]. Moving diagonally is not allowed.
//
//


class Solution {
private:
    int LongestPath(int x, int y, vector<vector<int>>& matrix, vector<vector<int>>& memory) {
        int height = matrix.size();
        int width = matrix[0].size();
        if (memory[y][x] > 0) return memory[y][x];
        int result = 0;
        int directions[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
        for (int i = 0; i < 4; i++) {
            int nx = x + directions[i][0];
            int ny = y + directions[i][1];
            if (nx < 0 || nx >= width) continue;
            if (ny < 0 || ny >= height) continue;
            if (matrix[ny][nx] <= matrix[y][x]) continue;
            result = max(result, LongestPath(nx, ny, matrix, memory));
        }
        memory[y][x] = result + 1;
        return result + 1;
    }
    
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        vector<vector<int>> memory(height, vector<int>(width, -1));
        int result = 0;
        for (int i = 0; i < height; ++i) {
            for (int j = 0; j < width; ++j) {
                result = max(result, LongestPath(j, i, matrix, memory));
            }
        }
        return result;
    }
};
