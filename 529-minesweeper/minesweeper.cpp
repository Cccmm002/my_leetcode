// Let's play the minesweeper game (Wikipedia, online game)! 
//
// You are given a 2D char matrix representing the game board. 'M' represents an unrevealed mine, 'E' represents an unrevealed empty square, 'B' represents a revealed blank square that has no adjacent (above, below, left, right, and all 4 diagonals) mines, digit ('1' to '8') represents how many mines are adjacent to this revealed square, and finally 'X' represents a revealed mine.
//
// Now given the next click position (row and column indices) among all the unrevealed squares ('M' or 'E'), return the board after revealing this position according to the following rules: 
//
//
//
// If a mine ('M') is revealed, then the game is over - change it to 'X'.
// If an empty square ('E') with no adjacent mines is revealed, then change it to revealed blank ('B') and all of its adjacent unrevealed squares should be revealed recursively.
// If an empty square ('E') with at least one adjacent mine is revealed, then change it to a digit ('1' to '8') representing the number of adjacent mines.
// Return the board when no more squares will be revealed.
//
//
//
// Example 1:
//
// Input: 
//
// [['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'M', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E'],
//  ['E', 'E', 'E', 'E', 'E']]
//
// Click : [3,0]
//
// Output: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Explanation:
//
//
//
//
// Example 2:
//
// Input: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'M', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Click : [1,2]
//
// Output: 
//
// [['B', '1', 'E', '1', 'B'],
//  ['B', '1', 'X', '1', 'B'],
//  ['B', '1', '1', '1', 'B'],
//  ['B', 'B', 'B', 'B', 'B']]
//
// Explanation:
//
//
//
//
//
//
// Note:
//
// The range of the input matrix's height and width is [1,50].
// The click position will only be an unrevealed square ('M' or 'E'), which also means the input board contains at least one clickable square.
// The input board won't be a stage when game is over (some mines have been revealed).
// For simplicity, not mentioned rules should be ignored in this problem. For example, you don't need to reveal all the unrevealed mines when the game is over, consider any cases that you will win the game or flag any squares.


class Solution {
private:
    void _click(vector<vector<char>>& board, int x, int y) {
        if (board[y][x] == 'M') {
            board[y][x] = 'X';
            return;
        }
        if (board[y][x] != 'E') return;
        int height = board.size();
        int width = board[0].size();
        int dir[8][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}, {1, 1}, {1, -1}, {-1, 1}, {-1, -1}};
        int mines = 0;
        vector<int> click_x, click_y;
        for (int i = 0; i < 8; i++) {
            int nx = x + dir[i][0];
            int ny = y + dir[i][1];
            if (nx < 0 || nx >= width) continue;
            if (ny < 0 || ny >= height) continue;
            if (board[ny][nx] == 'M') 
                mines++;
            else if (board[ny][nx] == 'E') {
                click_x.push_back(nx);
                click_y.push_back(ny);
            }
        }
        if (mines > 0) 
            board[y][x] = '0' + mines;
        else {
            board[y][x] = 'B';
            for (int i = 0; i < click_x.size(); i++)
                _click(board, click_x[i], click_y[i]);
        }
    }
    
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        _click(board, click[1], click[0]);
        return board;
    }
};
