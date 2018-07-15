// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up, down, left or right, but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction.
//
// Given the ball's start position, the destination and the maze, find the shortest distance for the ball to stop at the destination. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the destination (included). If the ball cannot stop at the destination, return -1.
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
// Output: 12
// Explanation: One shortest way is : left -> down -> left -> down -> right -> down -> right.
//              The total distance is 1 + 1 + 3 + 1 + 2 + 2 + 2 = 12.
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
// Output: -1
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


struct Node {
    int x;
    int y;
    int distance;
    
    Node(int xx, int yy, int dis) : x(xx), y(yy), distance(dis) {}
};

struct Comp {
    bool operator()(const Node& a, const Node& b) {
        return a.distance > b.distance;
    }
};
    
class Solution {
public:
    int shortestDistance(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int height = maze.size();
        if (height <= 0) return false;
        int width = maze[0].size();
        vector<vector<int>> visited(height);
        for (int i = 0; i < height; i++) {
            vector<int> v(width, INT_MAX);
            visited[i] = v;
        }
        Node sp(start[1], start[0], 0);
        priority_queue<Node, vector<Node>, Comp> q;
        q.push(sp);
        visited[sp.y][sp.x] = 0;
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            if (cur.x == destination[1] && cur.y == destination[0]) 
                return cur.distance;
            
            int left = cur.x;
            int d = 0;
            while(left - 1 >= 0 && maze[cur.y][left - 1] == 0) {
                left--;
                d++;
            }
            if (visited[cur.y][left] > d + cur.distance) {
                visited[cur.y][left] = d + cur.distance;
                Node next(left, cur.y, d + cur.distance);
                q.push(next);
            }
            int right = cur.x;
            d = 0;
            while(right + 1 <width && maze[cur.y][right + 1] == 0) {
                right++;
                d++;
            }
            if (visited[cur.y][right] > d + cur.distance) {
                visited[cur.y][right] = d + cur.distance;
                Node next(right, cur.y, d + cur.distance);
                q.push(next);
            }
            int up = cur.y;
            d = 0;
            while(up - 1 >= 0 && maze[up - 1][cur.x] == 0) {
                up--;
                d++;
            }
            if (visited[up][cur.x] > d + cur.distance) {
                visited[up][cur.x] = d + cur.distance;
                Node next(cur.x, up, d + cur.distance);
                q.push(next);
            }
            int down = cur.y;
            d = 0;
            while(down + 1 < height && maze[down + 1][cur.x] == 0) {
                down++;
                d++;
            }
            if (visited[down][cur.x] > d + cur.distance) {
                visited[down][cur.x] = d + cur.distance;
                Node next(cur.x, down, d + cur.distance);
                q.push(next);
            }
        }
        return -1;
    }
};
