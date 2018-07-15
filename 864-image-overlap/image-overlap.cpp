// Two images A and B are given, represented as binary, square matrices of the same size.  (A binary matrix has only 0s and 1s as values.)
//
// We translate one image however we choose (sliding it left, right, up, or down any number of units), and place it on top of the other image.  After, the overlap of this translation is the number of positions that have a 1 in both images.
//
// (Note also that a translation does not include any kind of rotation.)
//
// What is the largest possible overlap?
//
// Example 1:
//
//
// Input: A = [[1,1,0],
//             [0,1,0],
//             [0,1,0]]
//        B = [[0,0,0],
//             [0,1,1],
//             [0,0,1]]
// Output: 3
// Explanation: We slide A to right by 1 unit and down by 1 unit.
//
// Notes: 
//
//
// 	1 <= A.length = A[0].length = B.length = B[0].length <= 30
// 	0 <= A[i][j], B[i][j] <= 1
//
//


class Solution {
private:
    int counting(vector<vector<int>>& A, vector<vector<int>>& B, int hor, int vet) {
        int height = A.size();
        int width = A[0].size();
        int left = max(0, hor);
        int right = min(width, width + hor);
        int up = max(0, vet);
        int down = min(height, height + vet);
        int res = 0;
        for (int i = up; i < down; i++) {
            for (int j = left; j < right; j++) {
                res += A[i - vet][j - hor] & B[i][j];
            }
        }
        return res;
    }
    
public:
    int largestOverlap(vector<vector<int>>& A, vector<vector<int>>& B) {
        int height = A.size();
        int width = A[0].size();
        int res = 0;
        for (int i = -height + 1; i < height; i++) {
            for (int j = -width + 1; j < width; j++) {
                res = max(res, counting(A, B, j, i));
            }
        }
        return res;
    }
};
