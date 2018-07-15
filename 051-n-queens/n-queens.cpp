// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return all distinct solutions to the n-queens puzzle.
//
// Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space respectively.
//
// Example:
//
//
// Input: 4
// Output: [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
// Explanation: There exist two distinct solutions to the 4-queens puzzle as shown above.
//
//


class Solution {
private:
    void place(int current, int n, int *pos, vector<vector<string>> &res) {
        if (current == n) {
            vector<string> board;
            for (int i = 0; i < n; i++) {
                string line = "";
                for (int j = 0; j < n; j++) line += '.';
                line[pos[i]] = 'Q';
                board.push_back(line);
            }
            res.push_back(board);
        }
        for (int i = 0; i < n; i++) {   // Current placement: position i
            bool possible = true;
            for (int j = 0; j < current; j++) {
                if (pos[j] == i) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            for (int j = 1; i - j >= 0 && current - j >= 0; j++) {
                if (pos[current - j] == i - j) {
                    possible = false;
                    break;
                }
            }
            for (int j = 1; i + j < n && current - j >= 0; j++) {
                if (pos[current - j] == i + j) {
                    possible = false;
                    break;
                }
            }
            if (!possible) continue;
            pos[current] = i;
            place(current + 1, n, pos, res);
        }
    }
public:
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> res;
        if (n <= 0) return res;
        int *pos = new int[n];
        place(0, n, pos, res);
        return res;
    }
};

