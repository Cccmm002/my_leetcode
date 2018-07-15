// An image is represented by a binary matrix with 0 as a white pixel and 1 as a black pixel. The black pixels are connected, i.e., there is only one black region. Pixels are connected horizontally and vertically. Given the location (x, y) of one of the black pixels, return the area of the smallest (axis-aligned) rectangle that encloses all black pixels.
//
// Example:
//
//
// Input:
// [
//   "0010",
//   "0110",
//   "0100"
// ]
// and x = 0, y = 2
//
// Output: 6
//
//


class Solution {
public:
    int minArea(vector<vector<char>>& image, int x, int y) {
        int height = image.size();
        if (height == 0) return 0;
        int width = image[0].size();
        int left = width, right = 0;
        int up = height, down = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (image[i][j] == '0') continue;
                left = min(left, j);
                right = max(right, j);
                up = min(up, i);
                down = max(down, i);
            }
        }
        return (right - left + 1)*(down - up + 1);
    }
};
