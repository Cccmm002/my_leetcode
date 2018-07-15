// Given a collection of intervals, merge all overlapping intervals.
//
// Example 1:
//
//
// Input: [[1,3],[2,6],[8,10],[15,18]]
// Output: [[1,6],[8,10],[15,18]]
// Explanation: Since intervals [1,3] and [2,6] overlaps, merge them into [1,6].
//
//
// Example 2:
//
//
// Input: [[1,4],[4,5]]
// Output: [[1,5]]
// Explanation: Intervals [1,4] and [4,5] are considerred overlapping.
//


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return intervals;
        sort(intervals.begin(), intervals.end(), 
             [](const Interval &a, const Interval &b) -> bool {
                 return a.start < b.start;
             });
        vector<Interval> res;
        int current_start = intervals[0].start;
        int current_end = intervals[0].end;
        for (int i = 1; i < n; i++) {
            if (intervals[i].start <= current_end) {
                current_end = max(current_end, intervals[i].end);
            }
            else {
                res.push_back(Interval(current_start, current_end));
                current_start = intervals[i].start;
                current_end = intervals[i].end;
            }
        }
        res.push_back(Interval(current_start, current_end));
        return res;
    }
};
