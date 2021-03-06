// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, determine whether the ball could stop at the destination.
//
// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The start and destination coordinates are represented by row and column indexes.
//
//
// Example 1
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (4, 4)
//
// Output: true
// Explanation: One possible way is : left -> down -> left -> down -> right -> down -> right.
//
//
//
//
//
// Example 2
//
// Input 1: a maze represented by a 2D array
//
// 0 0 1 0 0
// 0 0 0 0 0
// 0 0 0 1 0
// 1 1 0 1 1
// 0 0 0 0 0
//
// Input 2: start coordinate (rowStart, colStart) = (0, 4)
// Input 3: destination coordinate (rowDest, colDest) = (3, 2)
//
// Output: false
// Explanation: There is no way for the ball to stop at the destination.
//
//
//
//
// Note:
//
// There is only one ball and one destination in the maze.
// Both the ball and the destination exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and both the width and height of the maze won't exceed 100.
//
//


class Solution {
public:
    bool hasPath(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int height = maze.size();
        if (height <= 0) return false;
        int width = maze[0].size();
        vector<vector<bool>> visited(height);
        for (int i = 0; i < height; i++) {
            vector<bool> v(width, false);
            visited[i] = v;
        }
        Point sp(start[1], start[0]);
        queue<Point> q;
        q.push(sp);
        visited[sp.y][sp.x] = true;
        while (!q.empty()) {
            Point cur = q.front();
            q.pop();
            if (cur.x == destination[1] && cur.y == destination[0]) return true;
            
            int left = cur.x;
            while(left - 1 >= 0 && maze[cur.y][left - 1] == 0) left--;
            if (!visited[cur.y][left]) {
                visited[cur.y][left] = true;
                Point next(left, cur.y);
                q.push(next);
            }
            int right = cur.x;
            while(right + 1 <width && maze[cur.y][right + 1] == 0) right++;
            if (!visited[cur.y][right]) {
                visited[cur.y][right] = true;
                Point next(right, cur.y);
                q.push(next);
            }
            int up = cur.y;
            while(up - 1 >= 0 && maze[up - 1][cur.x] == 0) up--;
            if (!visited[up][cur.x]) {
                visited[up][cur.x] = true;
                Point next(cur.x, up);
                q.push(next);
            }
            int down = cur.y;
            while(down + 1 < height && maze[down + 1][cur.x] == 0) down++;
            if (!visited[down][cur.x]) {
                visited[down][cur.x] = true;
                Point next(cur.x, down);
                q.push(next);
            }
        }
        return false;
    }
};
