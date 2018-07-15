// A 2d grid map of m rows and n columns is initially filled with water. We may perform an addLand operation which turns the water at position (row, col) into a land. Given a list of positions to operate, count the number of islands after each addLand operation. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example:
//
//
// Input: m = 3, n = 3, positions = [[0,0], [0,1], [1,2], [2,1]]
// Output: [1,1,2,3]
//
//
// Explanation:
//
// Initially, the 2d grid grid is filled with water. (Assume 0 represents water and 1 represents land).
//
//
// 0 0 0
// 0 0 0
// 0 0 0
//
//
// Operation #1: addLand(0, 0) turns the water at grid[0][0] into a land.
//
//
// 1 0 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #2: addLand(0, 1) turns the water at grid[0][1] into a land.
//
//
// 1 1 0
// 0 0 0   Number of islands = 1
// 0 0 0
//
//
// Operation #3: addLand(1, 2) turns the water at grid[1][2] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 2
// 0 0 0
//
//
// Operation #4: addLand(2, 1) turns the water at grid[2][1] into a land.
//
//
// 1 1 0
// 0 0 1   Number of islands = 3
// 0 1 0
//
//
// Follow up:
//
// Can you do it in time complexity O(k log mn), where k is the length of the positions?
//


struct Location {
    int x, y;
    Location(int xx, int yy) : x(xx), y(yy) {}
    bool operator == (const Location &other) const {
        return (x == other.x && y == other.y);
    }
};

struct Hasher {
    std::size_t operator()(const Location& k) const {
        return k.x ^ k.y;
    }
};

class UF {
private:
    Location **parents;
    int height;
    int width;

public:
    bool **land;
    
    UF(int m, int n) {
        height = m;
        width = n;
        parents = new Location*[m];
        land = new bool*[m];
        for (int i = 0; i < m; i++) {
            parents[i] = (Location*)malloc(sizeof(Location)*n);
            for (int j = 0; j < n; j++) {
                Location l(j ,i);
                parents[i][j] = l;
            }
            land[i] = new bool[n];
            for (int j = 0; j < n; j++)
                land[i][j] = false;
        }
    }
    
    ~UF() {
        for (int i = 0; i < height; i++) {
            free(parents[i]);
            delete[] land[i];
        }
        delete[] parents;
        delete[] land;
    }
    
    Location find(int x, int y) {
        if (parents[y][x].x == x && parents[y][x].y == y)
            return parents[y][x];
        Location loc = find(parents[y][x].x, parents[y][x].y);
        parents[y][x].x = loc.x;
        parents[y][x].y = loc.y;
        return loc;
    }
    
    void merge(Location l1, Location l2) {
        Location p1 = find(l1.x, l1.y);
        Location p2 = find(l2.x, l2.y);
        parents[p1.y][p1.x].x = p2.x;
        parents[p1.y][p1.x].y = p2.y;
    }
};

class Solution {
public:
    vector<int> numIslands2(int m, int n, vector<pair<int, int>>& positions) {
        int len = positions.size();
        vector<int> res;
        UF *u = new UF(m, n);
        int num = 0;
        for (int i = 0; i < len; i++) {
            u->land[positions[i].first][positions[i].second] = true;
            int dir[4][2] = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            Location cur(positions[i].second, positions[i].first);
            num++;
            for (int d = 0; d < 4; d++) {
                int nx = positions[i].second + dir[d][0];
                int ny = positions[i].first + dir[d][1];
                if (nx < 0 || nx >= n) continue;
                if (ny < 0 || ny >= m) continue;
                if (u->land[ny][nx]) {
                    Location p = u->find(nx, ny);
                    if (p.x != cur.x || p.y != cur.y) {
                        Location l1(nx, ny);
                        u->merge(cur, l1);
                        num--;
                        cur = u->find(cur.x, cur.y);
                    }
                }
            }
            res.push_back(num);
        }
        delete u;
        return res;
    }
};
