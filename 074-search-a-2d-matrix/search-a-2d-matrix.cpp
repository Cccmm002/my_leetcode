// Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
//
//
// 	Integers in each row are sorted from left to right.
// 	The first integer of each row is greater than the last integer of the previous row.
//
//
// Example 1:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 3
// Output: true
//
//
// Example 2:
//
//
// Input:
// matrix = [
//   [1,   3,  5,  7],
//   [10, 11, 16, 20],
//   [23, 30, 34, 50]
// ]
// target = 13
// Output: false
//


class Solution {
private:
    int width, height;
    
    inline int GetElement(vector<vector<int>>& matrix, int index) {
        int row = index / width;
        int col = index % width;
        return matrix[row][col];
    }
    
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        height = matrix.size();
        if (height == 0) return false;
        width = matrix[0].size();
        int left = 0, right = height*width - 1;
        while (left <= right) {
            int mid = left + (right - left)/2;
            int element = GetElement(matrix, mid);
            if (element == target)
                return true;
            else if (element < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
        return false;
    }
};
