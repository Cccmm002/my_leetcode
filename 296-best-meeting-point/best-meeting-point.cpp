// A group of two or more people wants to meet and minimize the total travel distance. You are given a 2D grid of values 0 or 1, where each 1 marks the home of someone in the group. The distance is calculated using Manhattan Distance, where distance(p1, p2) = |p2.x - p1.x| + |p2.y - p1.y|.
//
// Example:
//
//
// Input: 
//
// 1 - 0 - 0 - 0 - 1
// |   |   |   |   |
// 0 - 0 - 0 - 0 - 0
// |   |   |   |   |
// 0 - 0 - 1 - 0 - 0
//
// Output: 6 
//
// Explanation: Given three people living at (0,0), (0,4), and (2,2):
//              The point (0,2) is an ideal meeting point, as the total travel distance 
//              of 2+2+2=6 is minimal. So return 6.
//


class Solution {
public:
    int minTotalDistance(vector<vector<int>>& grid) {
        int height = grid.size();
        if (height == 0) return 0;
        int width = grid[0].size();
        vector<int> xs;
        vector<int> ys;
        int count = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 1) {
                    xs.push_back(j);
                    ys.push_back(i);
                    count++;
                }
            }
        }
        vector<int> mx(xs.begin(), xs.end());
        vector<int> my(ys.begin(), ys.end());
        int resx, resy;
        if (count%2 == 0) {
            int b = count/2;
            int a = b - 1;
            nth_element(mx.begin(), mx.begin() + a, mx.end()); int xa = mx[a];
            nth_element(mx.begin(), mx.begin() + b, mx.end()); int xb = mx[b];
            nth_element(my.begin(), my.begin() + a, my.end()); int ya = my[a];
            nth_element(my.begin(), my.begin() + b, my.end()); int yb = my[b];
            resx = (xa + xb)/2;
            resy = (ya + yb)/2;
        }
        else {
            int mid = count/2;
            nth_element(mx.begin(), mx.begin() + mid, mx.end()); resx = mx[mid];
            nth_element(my.begin(), my.begin() + mid, my.end()); resy = my[mid];
        }
        int dis = 0;
        for (int i = 0; i < count; i++) {
            dis += abs(resx - xs[i]) + abs(resy - ys[i]);
        }
        return dis;
    }
};
