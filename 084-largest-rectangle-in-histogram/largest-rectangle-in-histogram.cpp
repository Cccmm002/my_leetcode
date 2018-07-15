// Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram.
//
//
// Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//
//  
//
//
// The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//  
//
// Example:
//
//
// Input: [2,1,5,6,2,3]
// Output: 10
//
//


class Solution {
public:
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
};
