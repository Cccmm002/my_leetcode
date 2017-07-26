// Given an array of meeting time intervals consisting of start and end times [[s1,e1],[s2,e2],...] (si < ei), find the minimum number of conference rooms required.
//
//
// For example,
// Given [[0, 30],[5, 10],[15, 20]],
// return 2.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */

class Compare {
public:
    bool operator() (const Interval &a, const Interval &b) {
        return a.end > b.end;
    }
};

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), 
            [](const Interval &a, const Interval &b) -> bool {
                return a.start < b.start;
            });
        int len = intervals.size();
        priority_queue<Interval, vector<Interval>, Compare> pq;
        int res = 0;
        for (int i = 0; i < len; i++) {
            while ((!pq.empty()) && (pq.top().end <= intervals[i].start))
                pq.pop();
            pq.push(intervals[i]);
            res = max(res, int(pq.size()));
        }
        return res;
    }
};
