// Design a Snake game that is played on a device with screen size = width x height. Play the game online if you are not familiar with the game.
//
// The snake is initially positioned at the top left corner (0,0) with length = 1 unit.
//
// You are given a list of food's positions in row-column order. When a snake eats the food, its length and the game's score both increase by 1.
//
// Each food appears one by one on the screen. For example, the second food will not appear until the first food was eaten by the snake.
//
// When a food does appear on the screen, it is guaranteed that it will not appear on a block occupied by the snake.
//
//
// Example:
//
// Given width = 3, height = 2, and food = [[1,2],[0,1]].
//
// Snake snake = new Snake(width, height, food);
//
// Initially the snake appears at position (0,0) and the food at (1,2).
//
// |S| | |
// | | |F|
//
// snake.move("R"); -> Returns 0
//
// | |S| |
// | | |F|
//
// snake.move("D"); -> Returns 0
//
// | | | |
// | |S|F|
//
// snake.move("R"); -> Returns 1 (Snake eats the first food and right after that, the second food appears at (0,1) )
//
// | |F| |
// | |S|S|
//
// snake.move("U"); -> Returns 1
//
// | |F|S|
// | | |S|
//
// snake.move("L"); -> Returns 2 (Snake eats the second food)
//
// | |S|S|
// | | |S|
//
// snake.move("U"); -> Returns -1 (Game over because snake collides with border)
//
//
//
//
// Credits:Special thanks to @elmirap for adding this problem and creating all test cases.


typedef pair<int, int> Loc;

class SnakeGame {
private:
    vector<pair<int, int>> foods;
    int score;
    int foodPointer;
    queue<pair<int, int>> snake;
    pair<int, int> head;
    int width, height;
    vector<vector<bool>> body;
    
public:
    /** Initialize your data structure here.
        @param width - screen width
        @param height - screen height 
        @param food - A list of food positions
        E.g food = [[1,1], [1,0]] means the first food is positioned at [1,1], the second is at [1,0]. */
    SnakeGame(int _width, int _height, vector<pair<int, int>> food) {
        foods = food;
        score = 0;
        foodPointer = 0;
        Loc start(0, 0);
        snake.push(start);
        head = start;
        width = _width;
        height = _height;
        vector<vector<bool>> _body(height);
        for (int i = 0; i < height; i++) {
            vector<bool> b(width, false);
            _body[i] = b;
        }
        body = _body;
        body[0][0] = true;
    }
    
    /** Moves the snake.
        @param direction - 'U' = Up, 'L' = Left, 'R' = Right, 'D' = Down 
        @return The game's score after the move. Return -1 if game over. 
        Game over when snake crosses the screen boundary or bites its body. */
    int move(string direction) {
        //if (foodPointer >= foods.size()) return -1;
        int nx = head.second;
        int ny = head.first;
        if (direction == "L") nx--;
        else if (direction == "R") nx++;
        else if (direction == "U") ny--;
        else if (direction == "D") ny++;
        if (nx < 0 || nx >= width) return -1;
        if (ny < 0 || ny >= height) return -1;
        if (body[ny][nx]) {
            if (ny != snake.front().first || nx != snake.front().second)
                return -1;
        }
        
        if (nx == foods[foodPointer].second && ny == foods[foodPointer].first) {
            foodPointer++;
            score++;
        }
        else {
            Loc tail = snake.front();
            snake.pop();
            body[tail.first][tail.second] = false;
        }
        Loc l(ny, nx);
        head = l;
        snake.push(l);
        body[ny][nx] = true;
        return score;
    }
};

/**
 * Your SnakeGame object will be instantiated and called as such:
 * SnakeGame obj = new SnakeGame(width, height, food);
 * int param_1 = obj.move(direction);
 */
