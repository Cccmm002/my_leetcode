// Design a Tic-tac-toe game that is played between two players on a n x n grid.
//
//
// You may assume the following rules:
//
// A move is guaranteed to be valid and is placed on an empty block.
// Once a winning condition is reached, no more moves is allowed.
// A player who succeeds in placing n of their marks in a horizontal, vertical, or diagonal row wins the game.
//
//
//
// Example:
//
// Given n = 3, assume that player 1 is "X" and player 2 is "O" in the board.
//
// TicTacToe toe = new TicTacToe(3);
//
// toe.move(0, 0, 1); -> Returns 0 (no one wins)
// |X| | |
// | | | |    // Player 1 makes a move at (0, 0).
// | | | |
//
// toe.move(0, 2, 2); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 2 makes a move at (0, 2).
// | | | |
//
// toe.move(2, 2, 1); -> Returns 0 (no one wins)
// |X| |O|
// | | | |    // Player 1 makes a move at (2, 2).
// | | |X|
//
// toe.move(1, 1, 2); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 2 makes a move at (1, 1).
// | | |X|
//
// toe.move(2, 0, 1); -> Returns 0 (no one wins)
// |X| |O|
// | |O| |    // Player 1 makes a move at (2, 0).
// |X| |X|
//
// toe.move(1, 0, 2); -> Returns 0 (no one wins)
// |X| |O|
// |O|O| |    // Player 2 makes a move at (1, 0).
// |X| |X|
//
// toe.move(2, 1, 1); -> Returns 1 (player 1 wins)
// |X| |O|
// |O|O| |    // Player 1 makes a move at (2, 1).
// |X|X|X|
//
//
//
// Follow up:
// Could you do better than O(n2) per move() operation?
//


class TicTacToe {
private:
    int **board;
    int n;
    
public:
    /** Initialize your data structure here. */
    TicTacToe(int _n) {
        n = _n;
        board = new int*[n];
        for (int i = 0; i < n; i++) {
            board[i] = new int[n];
            for (int j = 0; j < n; j++)
                board[i][j] = 0;
        }
    }
    
    /** Player {player} makes a move at ({row}, {col}).
        @param row The row of the board.
        @param col The column of the board.
        @param player The player, can be either 1 or 2.
        @return The current winning condition, can be either:
                0: No one wins.
                1: Player 1 wins.
                2: Player 2 wins. */
    int move(int row, int col, int player) {
        board[col][row] = player;
        int dir[4][4] = {{-1, 0, 1, 0}, {0, -1, 0, 1}, {-1, -1, 1, 1}, {-1, 1, 1, -1}};
        for (int i = 0; i < 4; i++) {
            int ax = col, ay = row, bx = col, by = row;
            bool found = true;
            int num = 0;
            while (ax >= 0 && ay >= 0 && ay < n) {
                if (board[ax][ay] != player) {
                    found = false;
                    break;
                }
                ax += dir[i][0];
                ay += dir[i][1];
                num += 1;
            }
            while (bx < n && by >= 0 && by < n) {
                //cout<<"row: "<<row<<"; col: "<<col<<"; bx: "<<bx<<"; by:"<<by<<"; board:"<<board[bx][by]<<endl;
                if (board[bx][by] != player) {
                    found = false;
                    break;
                }
                bx += dir[i][2];
                by += dir[i][3];
                num += 1;
            }
            if (found) {
                if (n == num - 1)
                    return player;
            }
        }
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe obj = new TicTacToe(n);
 * int param_1 = obj.move(row,col,player);
 */
