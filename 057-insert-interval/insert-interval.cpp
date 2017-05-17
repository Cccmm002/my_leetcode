// Given a set of non-overlapping intervals, insert a new interval into the intervals (merge if necessary).
//
// You may assume that the intervals were initially sorted according to their start times.
//
//
// Example 1:
// Given intervals [1,3],[6,9], insert and merge [2,5] in as [1,5],[6,9].
//
//
//
// Example 2:
// Given [1,2],[3,5],[6,7],[8,10],[12,16], insert and merge [4,9] in as [1,2],[3,10],[12,16].
//
//
//
// This is because the new interval [4,9] overlaps with [3,5],[6,7],[8,10].


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
    vector<Interval> insert(vector<Interval>& intervals, Interval newInterval) {
        vector<Interval> res;
        Interval mid = newInterval;
        for (int i=0;i<intervals.size();i++) {
            if (intervals[i].end < mid.start) {
                res.push_back(intervals[i]);
                continue;
            }
            if (intervals[i].start < mid.start) {
                mid.start = intervals[i].start;
            }
            if (intervals[i].start <= mid.end && intervals[i].end > mid.end) {
                mid.end = intervals[i].end;
            }
            if (intervals[i].start > mid.end) {
                res.push_back(intervals[i]);
                continue;
            }
        }
        res.push_back(mid);
        sort(res.begin(), res.end(), 
            [](const Interval &a, const Interval &b) -> bool {
                return a.start < b.start;
            });
        return res;
    }
};
