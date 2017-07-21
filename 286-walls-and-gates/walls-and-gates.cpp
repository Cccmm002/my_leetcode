// You are given a m x n 2D grid initialized with these three possible values.
//
//
// -1 - A wall or an obstacle.
// 0 - A gate.
// INF - Infinity means an empty room. We use the value 231 - 1 = 2147483647 to represent INF as you may assume that the distance to a gate is less than 2147483647.
//
//
//
// Fill each empty room with the distance to its nearest gate. If it is impossible to reach a gate, it should be filled with INF.
//
//
// For example, given the 2D grid:
//
// INF  -1  0  INF
// INF INF INF  -1
// INF  -1 INF  -1
//   0  -1 INF INF
//
//
//
// After running your function, the 2D grid should be:
//
//   3  -1   0   1
//   2   2   1  -1
//   1  -1   2  -1
//   0  -1   3   4


typedef struct Cell {
    int x;
    int y;
    int distance;
    
    Cell(int xx, int yy, int dis) : x(xx), y(yy), distance(dis) {}
}*pCell;

class Solution {
public:
    void wallsAndGates(vector<vector<int>>& rooms) {
        int height = rooms.size();
        if (height == 0) return;
        int width = rooms[0].size();
        queue<Cell> q;
        for (int y = 0; y < height; y++) {
            for (int x = 0; x < width; x++) {
                if (rooms[y][x] == 0) {
                    Cell p(x, y, 0);
                    q.push(p);
                }
            }
        }
        int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while (!q.empty()) {
            Cell cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                int val = cur.distance + 1;
                Cell next_p(cur.x + directions[i][0], cur.y + directions[i][1], val);
                if (next_p.x < 0 || next_p.x >= width) continue;
                if (next_p.y < 0 || next_p.y >= height) continue;
                if (rooms[next_p.y][next_p.x] == -1) continue;
                if (val > rooms[next_p.y][next_p.x]) continue;
                rooms[next_p.y][next_p.x] = val;
                q.push(next_p);
            }
        }
    }
};
