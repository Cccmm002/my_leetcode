// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining.
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!
//
// Example:
//
//
// Input: [0,1,0,2,1,0,1,3,2,1,2,1]
// Output: 6


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        if (n == 0) return 0;
        int left = height[0], right = height[n - 1];
        int pl = 0, pr = n - 1;
        int res = 0;
        while (pl < pr) {
            if (height[pl] < height[pr]) {
                if (height[pl] > left)
                    left = height[pl];
                res += left - height[pl];
                pl++;
            }
            else {
                if (height[pr] > right)
                    right = height[pr];
                res += right - height[pr];
                pr--;
            }
        }
        return res;
    }
};
