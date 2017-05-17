// Given a 2D matrix matrix, find the sum of the elements inside the rectangle defined by its upper left corner (row1, col1) and lower right corner (row2, col2).
//
//
//
// The above rectangle (with the red border) is defined by (row1, col1) = (2, 1) and (row2, col2) = (4, 3), which contains sum = 8.
//
//
// Example:
//
// Given matrix = [
//   [3, 0, 1, 4, 2],
//   [5, 6, 3, 2, 1],
//   [1, 2, 0, 1, 5],
//   [4, 1, 0, 1, 7],
//   [1, 0, 3, 0, 5]
// ]
//
// sumRegion(2, 1, 4, 3) -> 8
// sumRegion(1, 1, 2, 2) -> 11
// sumRegion(1, 2, 2, 4) -> 12
//
//
//
// Note:
//
// You may assume that the matrix does not change.
// There are many calls to sumRegion function.
// You may assume that row1 &le; row2 and col1 &le; col2.


class NumMatrix {
private:
    int **s;
public:
    NumMatrix(vector<vector<int>> &matrix) {
        int row=matrix.size();
        if(row!=0) {
            int col=matrix[0].size();
            s=new int*[row+1];
            int *cols=new int[col+1];
            for(int i=0;i<row+1;i++)
                s[i]=new int[col+1];
            for(int i=0;i<row+1;i++)
                s[i][0]=0;
            for(int i=0;i<col+1;i++) {
                s[0][i]=0;
                cols[i]=0;
            }
            for(int i=1;i<row+1;i++)
                for(int j=1;j<col+1;j++) {
                    cols[j]+=matrix[i-1][j-1];
                    s[i][j]=s[i][j-1]+cols[j];
                }
            delete[] cols;
        }
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return s[row2+1][col2+1]-s[row1][col2+1]-s[row2+1][col1]+s[row1][col1];
    }
};


// Your NumMatrix object will be instantiated and called as such:
// NumMatrix numMatrix(matrix);
// numMatrix.sumRegion(0, 1, 2, 3);
// numMatrix.sumRegion(1, 2, 3, 4);