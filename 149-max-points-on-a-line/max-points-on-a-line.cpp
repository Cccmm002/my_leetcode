// Given n points on a 2D plane, find the maximum number of points that lie on the same straight line.
//
// Example 1:
//
//
// Input: [[1,1],[2,2],[3,3]]
// Output: 3
// Explanation:
// ^
// |
// |        o
// |     o
// |  o  
// +------------->
// 0  1  2  3  4
//
//
// Example 2:
//
//
// Input: [[1,1],[3,2],[5,3],[4,1],[2,3],[1,4]]
// Output: 4
// Explanation:
// ^
// |
// |  o
// |     o        o
// |        o
// |  o        o
// +------------------->
// 0  1  2  3  4  5  6
//
//


/**
 * Definition for a point.
 * struct Point {
 *     int x;
 *     int y;
 *     Point() : x(0), y(0) {}
 *     Point(int a, int b) : x(a), y(b) {}
 * };
 */
class Solution {
private:
    int gcd(int a, int b) {
        if (b == 0) return a;
        return gcd(b, a%b);
    }
    
public:
    int maxPoints(vector<Point>& points) {
        int len = points.size();
        if (len <= 0) return 0;
        int res = 0;
        for (int i = 0; i < len; i++) {
            Point cur = points[i];
            unordered_map<int, unordered_map<int, int>> m;  // x, y, count
            int dup_count = 1;
            for (int j = 0; j < len; j++) {
                if (i == j) continue;
                int dx = points[j].x - cur.x;
                int dy = points[j].y - cur.y;
                double slope;
                if (dx == 0 && dy == 0) {
                    dup_count++;
                    continue;
                }
                int g = gcd(dx, dy);
                if (g != 0) {
                    dx /= g;
                    dy /= g;
                }
                auto it1 = m.find(dx);
                if (it1 != m.end()) {
                    auto it2 = m[dx].find(dy);
                    if (it2 != m[dx].end()) {
                        m[dx][dy]++;
                    }
                    else {
                        m[dx][dy] = 1;
                    }
                }
                else {
                    unordered_map<int, int> mm;
                    mm[dy] = 1;
                    m[dx] = mm;
                }
            }
            int cur_ans = 0;
            auto it1 = m.begin();
            while (it1 != m.end()) {
                auto it2 = it1->second.begin();
                while (it2 != it1->second.end()) {
                    if (it2->second > cur_ans)
                        cur_ans = it2->second;
                    it2++;
                }
                it1++;
            }
            cur_ans += dup_count;
            if (cur_ans > res)
                res = cur_ans;
        }
        return res;
    }
};
