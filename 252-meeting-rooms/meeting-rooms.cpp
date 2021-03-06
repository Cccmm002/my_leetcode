// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), determine if a person could attend all meetings.
//
// Example 1:
//
//
// Input: [[0,30],[5,10],[15,20]]
// Output: false
//
//
// Example 2:
//
//
// Input: [[7,10],[2,4]]
// Output: true
//
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
    bool canAttendMeetings(vector<Interval>& intervals) {
        int n = intervals.size();
        if (n == 0) return true;
        sort(intervals.begin(), intervals.end(), 
                 [](const Interval &a, const Interval &b) -> bool {
                     return a.start < b.start;
            });
        int cur = intervals[0].end;
        for (int i = 1; i < n; i++) {
            if (intervals[i].start < cur) return false;
            cur = intervals[i].end;
        }
        return true;
    }
};
