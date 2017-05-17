// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//
// Integers in each row are sorted in ascending from left to right.
// Integers in each column are sorted in ascending from top to bottom.
//
//
//
//
// For example,
//
// Consider the following matrix:
//
//
// [
//   [1,   4,  7, 11, 15],
//   [2,   5,  8, 12, 19],
//   [3,   6,  9, 16, 22],
//   [10, 13, 14, 17, 24],
//   [18, 21, 23, 26, 30]
// ]
//
//
// Given target = 5, return true.
// Given target = 20, return false.


class Solution {
public:
    bool search(vector<vector<int>>& matrix, int pRow, int pCol, int target) {
        if(pRow>=matrix.size() || pCol<0) return false;
        int val=matrix[pRow][pCol];
        if(val<target) return search(matrix, pRow+1, pCol, target);
        if(val>target) return search(matrix, pRow, pCol-1, target);
        return true;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        return search(matrix, 0, matrix[0].size()-1,target);
    }
};
