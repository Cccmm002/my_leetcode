// Given an m x n matrix of non-negative integers representing the height of each unit cell in a continent, the "Pacific ocean" touches the left and top edges of the matrix and the "Atlantic ocean" touches the right and bottom edges.
//
// Water can only flow in four directions (up, down, left, or right) from a cell to another one with height equal or lower.
//
// Find the list of grid coordinates where water can flow to both the Pacific and Atlantic ocean.
//
// Note:
//
// The order of returned grid coordinates does not matter.
// Both m and n are less than 150.
//
//
// Example:
//
// Given the following 5x5 matrix:
//
//   Pacific ~   ~   ~   ~   ~ 
//        ~  1   2   2   3  (5) *
//        ~  3   2   3  (4) (4) *
//        ~  2   4  (5)  3   1  *
//        ~ (6) (7)  1   4   5  *
//        ~ (5)  1   1   2   4  *
//           *   *   *   *   * Atlantic
//
// Return:
//
// [[0, 4], [1, 3], [1, 4], [2, 2], [3, 0], [3, 1], [4, 0]] (positions with parentheses in above matrix).


class Solution {
private:
    void calc(vector<vector<int>>& matrix, int **arr, queue<pair<int,int>> &q) {
        int height=matrix.size();
        int width=matrix[0].size();
        while(!q.empty()) {
            int y=q.front().first;
            int x=q.front().second;
            q.pop();
            
            int mx[4][2]={{-1,0},{1,0},{0,-1},{0,1}};
            for(int i=0;i<4;i++) {
                int xx=x+mx[i][0];
                int yy=y+mx[i][1];
                if(xx<0 || xx>=width) continue;
                if(yy<0 || yy>=height) continue;
                if(arr[yy][xx]!=0) continue;
                if(matrix[yy][xx]<matrix[y][x]) continue;
                pair<int,int> np(yy,xx);
                q.push(np);
                arr[yy][xx]=1;
            }
        }
    }
public:
    vector<pair<int, int>> pacificAtlantic(vector<vector<int>>& matrix) {
        vector<pair<int, int>> res;
        int height=matrix.size();
        if(height==0) return res;
        int width=matrix[0].size();
        
        int **pac=(int**)malloc(sizeof(int*)*height);
        for(int i=0;i<height;i++)
            pac[i]=(int*)calloc(width,sizeof(width));
        int **atl=(int**)malloc(sizeof(int*)*height);
        for(int i=0;i<height;i++)
            atl[i]=(int*)calloc(width,sizeof(width));
            
        queue<pair<int,int>> qp,qa;
        for(int i=0;i<width;i++) {
            pair<int,int> pp(0,i);
            qp.push(pp);
            pac[0][i]=1;
            pair<int,int> pa(height-1,i);
            qa.push(pa);
            atl[height-1][i]=1;
        }
        for(int i=0;i<height;i++) {
            pair<int,int> pp(i,0);
            qp.push(pp);
            pac[i][0]=1;
            pair<int,int> pa(i,width-1);
            qa.push(pa);
            atl[i][width-1]=1;
        }
        
        calc(matrix,pac,qp);
        calc(matrix,atl,qa);
        
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                if(pac[i][j]==1 && atl[i][j]==1) {
                    pair<int,int> yp(i,j);
                    res.push_back(yp);
                }
            }
        }
        return res;
    }
};
