// Given a 2d grid map of '1's (land) and '0's (water), count the number of islands. An island is surrounded by water and is formed by connecting adjacent lands horizontally or vertically. You may assume all four edges of the grid are all surrounded by water.
//
// Example 1:
// 11110110101100000000
// Answer: 1
// Example 2:
// 11000110000010000011
// Answer: 3
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
struct point{
    int x,y;
    point(int xx, int yy) : x(xx), y(yy) {}
};

int numIslands(vector<vector<char>>& grid) {
    if(grid.size()<=0) return 0;
    int height=grid.size();
    int width=grid[0].size();
    int res=0;
    bool *visited=(bool*)malloc(height*width*sizeof(bool));
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++)
            visited[i*width+j]=false;
    for(int i=0;i<height;i++)
        for(int j=0;j<width;j++){  //grid[i][j] : [row][col]
            if(!(!visited[i*width+j] && grid[i][j]=='1')) continue;
            queue<point> q;
            q.push(point(j,i));
            res++;
            while(!q.empty()){
                point p=q.front();
                q.pop();
                if(p.x!=0) {
                    if (grid[p.y][p.x - 1] == '1' && !visited[p.y * width + p.x - 1]) {
                        q.push(point(p.x - 1, p.y));
                        visited[p.y * width + p.x - 1]=true;
                    }
                }
                if(p.x<width-1) {
                    if (grid[p.y][p.x + 1] == '1' && !visited[p.y * width + p.x + 1]) {
                        q.push(point(p.x + 1, p.y));
                        visited[p.y * width + p.x + 1]=true;
                    }
                }
                if(p.y!=0) {
                    if (grid[p.y - 1][p.x] == '1' && !visited[(p.y - 1) * width + p.x]) {
                        q.push(point(p.x, p.y - 1));
                        visited[(p.y - 1) * width + p.x]=true;
                    }
                }
                if(p.y<height-1) {
                    if (grid[p.y + 1][p.x] == '1' && !visited[(p.y + 1) * width + p.x]) {
                        q.push(point(p.x, p.y + 1));
                        visited[(p.y + 1) * width + p.x]=true;
                    }
                }
            }
        }
    return res;
}
};
