// There is a ball in a maze with empty spaces and walls. The ball can go through empty spaces by rolling up (u), down (d), left (l) or right (r), but it won't stop rolling until hitting a wall. When the ball stops, it could choose the next direction. There is also a hole in this maze. The ball will drop into the hole if it rolls on to the hole.
//
//  Given the ball position, the hole position and the maze, find out how the ball could drop into the hole by moving the shortest distance. The distance is defined by the number of empty spaces traveled by the ball from the start position (excluded) to the hole (included). Output the moving directions by using 'u', 'd', 'l' and 'r'. Since there could be several different shortest ways, you should output the lexicographically smallest way. If the ball cannot reach the hole, output "impossible".
//
// The maze is represented by a binary 2D array. 1 means the wall and 0 means the empty space. You may assume that the borders of the maze are all walls. The ball and the hole coordinates are represented by row and column indexes.
//
//
// Example 1
//
// Input 1: a maze represented by a 2D array
//
// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0
//
// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (0, 1)
//
// Output: "lul"
// Explanation: There are two shortest ways for the ball to drop into the hole.
// The first way is left -> up -> left, represented by "lul".
// The second way is up -> left, represented by 'ul'.
// Both ways have shortest distance 6, but the first way is lexicographically smaller because 'l' < 'u'. So the output is "lul".
//
//
//
//
//
// Example 2
//
// Input 1: a maze represented by a 2D array
//
// 0 0 0 0 0
// 1 1 0 0 1
// 0 0 0 0 0
// 0 1 0 0 1
// 0 1 0 0 0
//
// Input 2: ball coordinate (rowBall, colBall) = (4, 3)
// Input 3: hole coordinate (rowHole, colHole) = (3, 0)
// Output: "impossible"
// Explanation: The ball cannot reach the hole.
//
//
//
//
// Note:
//
// There is only one ball and one hole in the maze.
// Both the ball and hole exist on an empty space, and they will not be at the same position initially.
// The given maze does not contain border (like the red rectangle in the example pictures), but you could assume the border of the maze are all walls.
// The maze contains at least 2 empty spaces, and the width and the height of the maze won't exceed 30.


bool string_cmp(string a, string b) {
    int sizeA = a.size();
    int sizeB = b.size();
    int len = min(sizeA, sizeB);
    for (int i = 0; i < len; i++) {
        if (a[i] < b[i]) return true;
        else if (a[i] > b[i]) return false;
    }
    return sizeA < sizeB;
}

struct Node {
    int x;
    int y;
    int distance;
    string path;
    
    Node(int xx, int yy, int dis, string p) : x(xx), y(yy), distance(dis), path(p) {}
};

struct Comp {
    bool operator()(const Node& a, const Node& b) {
        if (a.distance > b.distance) return true;
        else if (a.distance < b.distance) return false;
        else return !string_cmp(a.path, b.path);
    }
};

class Solution {
private:
    inline bool smaller(int ori_length, string ori_path, int l, string p) {
        if (l < ori_length) return true;
        else if (l > ori_length) return false;
        else return string_cmp(p, ori_path);
    }
    
public:
    string findShortestWay(vector<vector<int>>& maze, vector<int>& start, vector<int>& destination) {
        int height = maze.size();
        if (height <= 0) return "impossible";
        int width = maze[0].size();
        vector<vector<int>> visited(height);
        vector<vector<string>> visited_path(height);
        for (int i = 0; i < height; i++) {
            vector<int> v(width, INT_MAX);
            vector<string> vp(width, "");
            visited[i] = v;
            visited_path[i] = vp;
        }
        int res_length = INT_MAX;
        string res_path = "";
        Node sp(start[1], start[0], 0, "");
        priority_queue<Node, vector<Node>, Comp> q;
        q.push(sp);
        visited[sp.y][sp.x] = 0;
        while (!q.empty()) {
            Node cur = q.top();
            q.pop();
            
            int left = cur.x;
            int d = 0;
            bool ended = false;
            while(left - 1 >= 0 && maze[cur.y][left - 1] == 0) {
                if (left - 1 == destination[1] && cur.y == destination[0]) {
                    if (smaller(res_length, res_path, d + cur.distance, cur.path + "l")) {
                        res_length = d + cur.distance;
                        res_path = cur.path + "l";
                        ended = true;
                    }
                }
                left--;
                d++;
            }
            if (!ended && (visited[cur.y][left] > d + cur.distance || 
                          (visited[cur.y][left] == d + cur.distance && string_cmp(cur.path + "l", visited_path[cur.y][left])))) {
                visited_path[cur.y][left] = cur.path + "l";
                visited[cur.y][left] = d + cur.distance;
                Node next(left, cur.y, d + cur.distance, cur.path + "l");
                q.push(next);
            }
            int right = cur.x;
            d = 0;
            ended = false;
            while(right + 1 < width && maze[cur.y][right + 1] == 0) {
                if (right + 1 == destination[1] && cur.y == destination[0]) {
                    if (smaller(res_length, res_path, d + cur.distance, cur.path + "r")) {
                        res_length = d + cur.distance;
                        res_path = cur.path + "r";
                        ended = true;
                    }
                }
                right++;
                d++;
            }
            if (!ended && (visited[cur.y][right] > d + cur.distance || 
                        (visited[cur.y][right] == d + cur.distance && string_cmp(cur.path + "r", visited_path[cur.y][right])))) {
                visited_path[cur.y][right] = cur.path + "r";
                visited[cur.y][right] = d + cur.distance;
                Node next(right, cur.y, d + cur.distance, cur.path + "r");
                q.push(next);
            }
            int up = cur.y;
            d = 0;
            ended = false;
            while(up - 1 >= 0 && maze[up - 1][cur.x] == 0) {
                if (up - 1 == destination[0] && cur.x == destination[1]) {
                    if (smaller(res_length, res_path, d + cur.distance, cur.path + "u")) {
                        res_length = d + cur.distance;
                        res_path = cur.path + "u";
                        ended = true;
                    }
                }
                up--;
                d++;
            }
            if (!ended && (visited[up][cur.x] > d + cur.distance || 
                          (visited[up][cur.x] == d + cur.distance && string_cmp(cur.path + "u", visited_path[up][cur.x])))) {
                visited_path[up][cur.x] = cur.path + "u";
                visited[up][cur.x] = d + cur.distance;
                Node next(cur.x, up, d + cur.distance, cur.path + "u");
                q.push(next);
            }
            int down = cur.y;
            d = 0;
            ended = false;
            while(down + 1 < height && maze[down + 1][cur.x] == 0) {
                if (down + 1 == destination[0] && cur.x == destination[1]) {
                    if (smaller(res_length, res_path, d + cur.distance, cur.path + "d")) {
                        res_length = d + cur.distance;
                        res_path = cur.path + "d";
                        ended = true;
                    }
                }
                down++;
                d++;
            }
            if (!ended && (visited[down][cur.x] > d + cur.distance || 
                          (visited[down][cur.x] == d + cur.distance && string_cmp(cur.path + "d", visited_path[down][cur.x])))) {
                visited_path[down][cur.x] = cur.path + "d";
                visited[down][cur.x] = d + cur.distance;
                Node next(cur.x, down, d + cur.distance, cur.path + "d");
                q.push(next);
            }
        }
        if (res_path == "") return "impossible";
        else return res_path;
    }
};
