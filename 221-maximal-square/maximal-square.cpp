// Given a 2D binary matrix filled with 0's and 1's, find the largest square containing only 1's and return its area.
//
//
// For example, given the following matrix:
//
// 1 0 1 0 0
// 1 0 1 1 1
// 1 1 1 1 1
// 1 0 0 1 0
//
// Return 4.
//
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int height=matrix.size();
        if(height==0) return 0;
        int width=matrix[0].size();
        int max=0;
        int **m=new int*[height];
        for(int i=0;i<height;i++)
            m[i]=new int[width];
        m[0][0]=matrix[0][0]=='1'?1:0;
        for(int i=0;i<height;i++) {
            for(int j=0;j<width;j++) {
                int cur=matrix[i][j]=='1'?1:0;
                if(!(i==0 && j==0)) {
                    if(j==0) m[i][j]=cur+m[i-1][j];
                    else if(i==0) m[i][j]=cur+m[i][j-1];
                    else m[i][j]=cur+m[i-1][j]+m[i][j-1]-m[i-1][j-1];
                }
                if(cur==1) {
                    int s=(i>j?j:i)+1;
                    for(int k=1;k<=s;k++) {
                        int ii=i-k;
                        int jj=j-k;
                        int sum=m[i][j];
                        if(ii>=0) sum-=m[ii][j];
                        if(jj>=0) sum-=m[i][jj];
                        if(ii>=0 && jj>=0) sum+=m[ii][jj];
                        if(sum==(k*k)) max=max>sum?max:sum;
                    }
                }
            }
        }
        
        for(int i=0;i<height;i++)
            delete[] m[i];
        delete[] m;
        
        return max;
    }
};
