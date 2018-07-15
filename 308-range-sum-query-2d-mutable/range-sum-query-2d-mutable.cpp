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
// update(3, 2, 2)
// sumRegion(2, 1, 4, 3) -> 10
//
//
//
// Note:
//
// The matrix is only modifiable by the update function.
// You may assume the number of calls to update and sumRegion function is distributed evenly.
// You may assume that row1 ≤ row2 and col1 ≤ col2.
//
//


typedef struct Node {
    int row1, col1, row2, col2;
    int sum;
    Node *na, *nb, *nc, *nd;
    
    Node(int r1, int c1, int r2, int c2, vector<vector<int>> &presum) {
        row1 = r1; col1 = c1; col2 = c2; row2 = r2;
        na = NULL; nb = NULL; nc = NULL; nd = NULL;
        sum = presum[r2 + 1][c2 + 1] - presum[r1][c2 + 1] - presum[r2 + 1][c1] + presum[r1][c1];
        if (r1 == r2 && c1 == c2)
            return;
        else if (r1 == r2) {
            int m = (c1 + c2)/2;
            na = new Node(r1, c1, r2, m, presum);
            nb = new Node(r1, m + 1, r2, c2, presum);
        }
        else if (c1 == c2) {
            int m = (r1 + r2)/2;
            na = new Node(r1, c1, m, c2, presum);
            nc = new Node(m + 1, c1, r2, c2, presum);
        }
        else {
            int mr = (r1 + r2)/2;
            int mc = (c1 + c2)/2;
            na = new Node(r1, c1, mr, mc, presum);
            nb = new Node(r1, mc + 1, mr, c2, presum);
            nc = new Node(mr + 1, c1, r2, mc, presum);
            nd = new Node(mr + 1, mc + 1, r2, c2, presum);
        }
    }
    
    int query(int r1, int c1, int r2, int c2) {
        if (r2 < row1 || r1 > row2 || c2 < col1 || c1 > col2)
            return 0;
        int res = 0;
        if (r1 <= row1 && r2 >= row2 && c1 <= col1 && c2 >= col2) {
            res = sum;
        }
        else {
            if (na != NULL) res += na->query(r1, c1, r2, c2);
            if (nb != NULL) res += nb->query(r1, c1, r2, c2);
            if (nc != NULL) res += nc->query(r1, c1, r2, c2);
            if (nd != NULL) res += nd->query(r1, c1, r2, c2);
        }
        return res;
    }
    
    int update(int r, int c, int value) {
        if (r == row1 && r == row2 && c == col1 && c == col2) {
            int diff = value - sum;
            sum = value;
            return diff;
        }
        if (r < row1 || r > row2 || c < col1 || c > col2)
            return 0;
        int diff = 0;
        int mr = (row1 + row2)/2;
        int mc = (col1 + col2)/2;
        if (r <= mr && c <= mc) diff = na->update(r, c, value);
        if (r <= mr && c > mc) diff = nb->update(r, c, value);
        if (r > mr && c <= mc) diff = nc->update(r, c, value);
        if (r > mr && c > mc) diff = nd->update(r, c, value);
        sum += diff;
        return diff;
    }
}*pNode;

class NumMatrix {
private:
    pNode root;
    
public:
    NumMatrix(vector<vector<int>> matrix) {
        int height = matrix.size();
        if (height == 0) return;
        int width = matrix[0].size();
        vector<vector<int>> presum(height + 1, vector<int>(width + 1, 0));
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                presum[i + 1][j + 1] = presum[i][j + 1] + presum[i + 1][j] - presum[i][j] + matrix[i][j];
            }
        }
        root = new Node(0, 0, height - 1, width - 1, presum);
    }
    
    void update(int row, int col, int val) {
        root->update(row, col, val);
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return root->query(row1, col1, row2, col2);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * obj.update(row,col,val);
 * int param_2 = obj.sumRegion(row1,col1,row2,col2);
 */
