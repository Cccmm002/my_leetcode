// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
//
// Integers in each row are sorted from left to right.
// The first integer of each row is greater than the last integer of the previous row.
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
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
//
//
// Given target = 3, return true.


class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row=matrix.size();
        int col=matrix[0].size();
        int end=row*col-1;
        int begin=0;
        while(begin<end){
            int med=(begin+end)/2;
            int val=matrix[med/col][med%col];
            if(val>target) end=med-1;
            else if(val<target) begin=med+1;
            else return true;
        }
        if(matrix[begin/col][begin%col]==target) return true;
        else return false;
    }
};
