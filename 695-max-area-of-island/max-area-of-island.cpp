// Given a non-empty 2D array grid of 0's and 1's, an island is a group of 1's (representing land) connected 4-directionally (horizontal or vertical.)  You may assume all four edges of the grid are surrounded by water.
//
// Find the maximum area of an island in the given 2D array.
// (If there is no island, the maximum area is 0.)
//
// Example 1:
//
// [[0,0,1,0,0,0,0,1,0,0,0,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,1,1,0,1,0,0,0,0,0,0,0,0],
//  [0,1,0,0,1,1,0,0,1,0,1,0,0],
//  [0,1,0,0,1,1,0,0,1,1,1,0,0],
//  [0,0,0,0,0,0,0,0,0,0,1,0,0],
//  [0,0,0,0,0,0,0,1,1,1,0,0,0],
//  [0,0,0,0,0,0,0,1,1,0,0,0,0]]
//
// Given the above grid, return 6.
//
// Note the answer is not 11, because the island must be connected 4-directionally.
//
//
// Example 2:
// [[0,0,0,0,0,0,0,0]]
// Given the above grid, return 0.
//
//
// Note:
// The length of each dimension in the given grid does not exceed 50.


class UF {
public:
    vector<vector<pair<int, int>>> parents;
    vector<vector<int>> counts;
    int height, width;
    
    UF (int h, int w, vector<vector<int>>& grid) {
        height = h;
        width = w;
        vector<vector<pair<int, int>>> vp(h);
        vector<vector<int>> vc(h);
        for (int i = 0; i < h; i++) {
            vector<pair<int, int>> v(w);
            vector<int> c(w);
            for (int j = 0; j < w; j++) {
                v[j] = make_pair(i, j);
                c[j] = grid[i][j];
            }
            vp[i] = v;
            vc[i] = c;
        }
        parents = vp;
        counts = vc;
    }
    
    pair<int, int> getParent(int h, int w) {
        int resh = h;
        int resw = w;
        while (resh != parents[resh][resw].first || resw != parents[resh][resw].second) {
            pair<int, int> ppp = parents[resh][resw];
            resh = ppp.first;
            resw = ppp.second;
        }
        pair<int, int> res = make_pair(resh, resw);
        parents[h][w] = res;
        return res;
    }
    
    int concate(int h1, int w1, int h2, int w2) {
        pair<int, int> p1 = getParent(h1, w1);
        pair<int, int> p2 = getParent(h2, w2);
        if (p1.first == p2.first && p1.second == p2.second)
            return counts[p1.first][p1.second];
        parents[p2.first][p2.second] = make_pair(p1.first, p1.second);
        //cout<<h1<<" "<<w1<<" "<<h2<<" "<<w2<<endl;
        //cout<<counts[p1.first][p1.second]<<" "<<counts[p2.first][p2.second]<<endl;
        int res = counts[p1.first][p1.second] + counts[p2.first][p2.second];
        counts[p1.first][p1.second] = res;
        return res;
    }
};

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int height = grid.size();
        if (height == 0) return 0;
        int width = grid[0].size();
        int res = 0;
        UF *uf = new UF(height, width, grid);
        int dirs[2][2] = {{0, -1}, {-1, 0}};
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (grid[i][j] == 0) continue;
                res = max(res, 1);
                for (int k = 0; k < 2; k++) {
                    int h = i + dirs[k][0];
                    int w = j + dirs[k][1];
                    if (h < 0 || w < 0) continue;
                    if (grid[h][w] == 1) {
                        int r = uf->concate(h, w, i, j);
                        //cout<<r<<" "<<h<<" "<<w<<" "<<i<<" "<<j<<endl;
                        //cout<<"r="<<r<<endl;
                        res = max(res, r);
                        //cout<<"res="<<res<<endl;
                    }
                }
            }
        }
        delete uf;
        return res;
    }
};
