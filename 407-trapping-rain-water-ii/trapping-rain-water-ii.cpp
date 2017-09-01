// Given an m x n matrix of positive integers representing the height of each unit cell in a 2D elevation map, compute the volume of water it is able to trap after raining.
//
//
// Note:
// Both m and n are less than 110. The height of each unit cell is greater than 0 and is less than 20,000.
//
//
// Example:
//
// Given the following 3x6 height map:
// [
//   [1,4,3,1,3,2],
//   [3,2,1,3,2,4],
//   [2,3,3,2,3,1]
// ]
//
// Return 4.
//
//
//
//
//
// The above image represents the elevation map [[1,4,3,1,3,2],[3,2,1,3,2,4],[2,3,3,2,3,1]] before the rain.
//
//
//
//
// After the rain, water are trapped between the blocks. The total volume of water trapped is 4.


struct Cell {
    int x, y, h;
    Cell(int xx, int yy, int hh) : x(xx), y(yy), h(hh) {}
};

struct Comp {
    bool operator()(const Cell& a, const Cell& b) {
        return a.h > b.h;
    }
};

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int height = heightMap.size();
        if (height == 0) return 0;
        int width = heightMap[0].size();
        priority_queue<Cell, vector<Cell>, Comp> pq;
        vector<vector<bool>> visited(height);
        for (int i = 0; i < height; i++) {
            vector<bool> v(width, false);
            visited[i] = v;
        }
        for (int i = 0; i < width; i++) {
            Cell c1(i, 0, heightMap[0][i]);
            Cell c2(i, height - 1, heightMap[height - 1][i]);
            pq.push(c1);
            pq.push(c2);
            visited[0][i] = true;
            visited[height - 1][i] = true;
        }
        for (int i = 0; i < height; i++) {
            if (!visited[i][0]) {
                Cell c(0, i, heightMap[i][0]);
                pq.push(c);
                visited[i][0] = true;
            }
            if (!visited[i][width - 1]) {
                Cell c(width - 1, i, heightMap[i][width - 1]);
                pq.push(c);
                visited[i][width - 1] = true;
            }
        }
        int res = 0;
        int dir[4][2] = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};
        while (!pq.empty()) {
            Cell c = pq.top();
            pq.pop();
            for (int i = 0; i < 4; i++) {
                int nx = c.x + dir[i][0];
                int ny = c.y + dir[i][1];
                if (nx < 0 || nx >= width) continue;
                if (ny < 0 || ny >= height) continue;
                if (visited[ny][nx]) continue;
                visited[ny][nx] = true;
                if (c.h > heightMap[ny][nx])
                    res += (c.h - heightMap[ny][nx]);
                Cell nc(nx, ny, max(heightMap[ny][nx], c.h));
                pq.push(nc);
            }
        }
        return res;
    }
};
