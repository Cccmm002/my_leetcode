// Given a matrix consists of 0 and 1, find the distance of the nearest 0 for each cell.
//
// The distance between two adjacent cells is 1.
//
// Example 1: 
// Input:
//
// 0 0 0
// 0 1 0
// 0 0 0
//
// Output:
//
// 0 0 0
// 0 1 0
// 0 0 0
//
//
//
// Example 2: 
// Input:
//
// 0 0 0
// 0 1 0
// 1 1 1
//
// Output:
//
// 0 0 0
// 0 1 0
// 1 2 1
//
//
//
// Note:
//
// The number of elements of the given matrix will not exceed 10,000.
// There are at least one 0 in the given matrix.
// The cells are adjacent in only four directions: up, down, left and right.


class Solution {
private:
    struct Point {
        int x;
        int y;
        
        Point(int xx, int yy) : x(xx), y(yy) {}
    };
    
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int w = matrix.size();
        if(w == 0) return matrix;
        int h = matrix[0].size();
        vector<vector<int>> res(w);
        for(int i=0;i<w;i++) {
            vector<int> a(h);
            res[i] = a;
        }
        queue<Point> q;
        for(int i = 0;i<w;i++) {
            for(int j=0;j<h;j++) {
                if(matrix[i][j] == 0) {
                    q.push(Point(i, j));
                    res[i][j] = 0;
                }
                else {
                    res[i][j] = INT_MAX;
                }
            }
        }
        int directions[4][2] = {{0, -1}, {0, 1}, {1, 0}, {-1, 0}};
        while(!q.empty()) {
            Point cur = q.front();
            q.pop();
            for(int i=0;i<4;i++) {
                int nx = cur.x + directions[i][0];
                int ny = cur.y + directions[i][1];
                if(nx < 0 || nx >= w) continue;
                if(ny < 0 || ny >= h) continue;
                if(res[nx][ny] == 0) continue;
                if(res[nx][ny] > res[cur.x][cur.y] + 1) {
                    q.push(Point(nx, ny));
                    res[nx][ny] = res[cur.x][cur.y] + 1;
                }
            }
        }
        return res;
    }
};

