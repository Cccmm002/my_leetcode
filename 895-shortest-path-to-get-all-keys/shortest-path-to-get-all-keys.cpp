// We are given a 2-dimensional grid. "." is an empty cell, "#" is a wall, "@" is the starting point, ("a", "b", ...) are keys, and ("A", "B", ...) are locks.
//
// We start at the starting point, and one move consists of walking one space in one of the 4 cardinal directions.  We cannot walk outside the grid, or walk into a wall.  If we walk over a key, we pick it up.  We can't walk over a lock unless we have the corresponding key.
//
// For some 1 <= K <= 6, there is exactly one lowercase and one uppercase letter of the first K letters of the English alphabet in the grid.  This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
//
// Return the lowest number of moves to acquire all keys.  If it's impossible, return -1.
//
//  
//
//
// Example 1:
//
//
// Input: ["@.a.#","###.#","b.A.B"]
// Output: 8
//
//
//
// Example 2:
//
//
// Input: ["@..aA","..B#.","....b"]
// Output: 6
//
//
//
//  
//
// Note:
//
//
// 	1 <= grid.length <= 30
// 	1 <= grid[0].length <= 30
// 	grid[i][j] contains only '.', '#', '@', 'a'-'f' and 'A'-'F'
// 	The number of keys is in [1, 6].  Each key has a different letter and opens exactly one lock.
//
//
//


class Solution {
private:
    inline int setBit(int num, int bit) {
        return num | (1 << bit);
    }
    
    inline bool getBit(int num, int bit) {
        int b = (num >> bit) & 1;
        return b == 1 ? true : false;
    }
    
    tuple<int, int, int> findAllKeys(vector<string>& grid) {
        int res = 0;
        int starting_x, starting_y;
        int height = grid.size();
        int width = grid[0].size();
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                char c = grid[i][j];
                if (c >= 'a' && c <= 'f') {
                    int n = c - 'a';
                    res = setBit(res, n);
                }
                else if (c == '@') {
                    starting_x = j;
                    starting_y = i;
                }
            }
        }
        return tuple<int, int, int>(res, starting_y, starting_x);
    }
    
public:
    int shortestPathAllKeys(vector<string>& grid) {
        int height = grid.size();
        int width = grid[0].size();
        tuple<int, int, int> tt = findAllKeys(grid);
        int target = get<0>(tt);
        vector<vector<vector<bool>>> visited(height, vector<vector<bool>>(width, vector<bool>(64, false)));
        queue<tuple<int, int, int>> q;    // height, width, mask
        tuple<int, int, int> start(get<1>(tt), get<2>(tt), 0);
        q.push(start);
        visited[get<1>(tt)][get<2>(tt)][0] = true;
        int level = 0;
        int directions[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};
        while (!q.empty()) {
            int count = q.size();
            level += 1;
            for (int i = 0; i < count; i++) {
                tuple<int, int, int> cur = q.front();
                q.pop();
                int keys = get<2>(cur);
                int h = get<0>(cur), w = get<1>(cur);
                char c = grid[h][w];
                if (c == '#')
                    continue;
                if (c >= 'a' && c <= 'f') {
                    int b = c - 'a';
                    keys = setBit(keys, b);
                }
                if (keys == target)
                    return level - 1;
                if (c >= 'A' && c <= 'F') {
                    int b = c - 'A';
                    if (!getBit(keys, b))
                        continue;
                }
                for (int d = 0; d < 4; d++) {
                    int nh = h + directions[d][0], nw = w + directions[d][1];
                    if (nh >= height || nh < 0) continue;
                    if (nw >= width || nw < 0) continue;
                    if (grid[nh][nw] == '#') continue;
                    tuple<int, int, int> nt(nh, nw, keys);
                    if (visited[nh][nw][keys]) continue;
                    visited[nh][nw][keys] = true;
                    q.push(nt);
                }
            }
        }
        
        return -1;
    }
};
