// Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it is able to trap after raining. 
//
//
//
// For example, 
// Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.
//
//
//
//
// The above elevation map is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped. Thanks Marcos for contributing this image!


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);
        int left_max = -1, right_max = -1;
        for (int i = 0; i < n; i++) {
            left_max = max(left_max, height[i]);
            right_max = max(right_max, height[n - i - 1]);
            left[i] = left_max;
            right[n - i - 1] = right_max;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            int wall = min(left[i], right[i]);
            if (height[i] < wall)
                res += (wall - height[i]);
        }
        return res;
    }
};
