// Given a 2D binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.
//
// Example:
//
//
// Input:
// [
//   ["1","0","1","0","0"],
//   ["1","0","1","1","1"],
//   ["1","1","1","1","1"],
//   ["1","0","0","1","0"]
// ]
// Output: 6
//
//


class Solution {
private:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        if (n == 0) return 0;
        int res = 0;
        stack<int> s;
        s.push(0);
        for (int i = 1; i < n; i++) {
            while (!s.empty() && heights[i] < heights[s.top()]) {
                int cur = s.top();
                s.pop();
                int left = s.empty() ? -1 : s.top();
                int area = (i - left - 1) * heights[cur];
                res = max(res, area);
            }
            s.push(i);
        }
        while (!s.empty()) {
            int cur = s.top();
            s.pop();
            int prev = s.empty() ? -1 : s.top();
            int area = (n - prev - 1) * heights[cur];
            res = max(res, area);
        }
        return res;
    }
    
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int height = matrix.size();
        if (height == 0) return 0;
        int width = matrix[0].size();
        vector<int> hist(width, 0);
        int res = 0;
        for (int i = 0; i < height; i++) {
            for (int j = 0; j < width; j++) {
                if (matrix[i][j] == '1') 
                    hist[j] += 1;
                else
                    hist[j] = 0;
            }
            int cur = largestRectangleArea(hist);
            res = max(res, cur);
        }
        return res;
    }
};
