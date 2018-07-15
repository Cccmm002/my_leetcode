// The n-queens puzzle is the problem of placing n queens on an n×n chessboard such that no two queens attack each other.
//
//
//
// Given an integer n, return the number of distinct solutions to the n-queens puzzle.
//
// Example:
//
//
// Input: 4
// Output: 2
// Explanation: There are two distinct solutions to the 4-queens puzzle as shown below.
// [
//  [".Q..",  // Solution 1
//   "...Q",
//   "Q...",
//   "..Q."],
//
//  ["..Q.",  // Solution 2
//   "Q...",
//   "...Q",
//   ".Q.."]
// ]
//
//


class Solution {
private:
    void place(int current, int n, int *pos, int *res) {
        if (current == n) {
            *res += 1;
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
    int totalNQueens(int n) {
        if (n <= 0) return 0;
        int res = 0;
        int *pos = new int[n];
        place(0, n, pos, &res);
        return res;
    }
};
