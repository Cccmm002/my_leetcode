// Given a data stream input of non-negative integers a1, a2, ..., an, ..., summarize the numbers seen so far as a list of disjoint intervals.
//
// For example, suppose the integers from the data stream are 1, 3, 7, 2, 6, ..., then the summary will be:
//
// [1, 1]
// [1, 1], [3, 3]
// [1, 1], [3, 3], [7, 7]
// [1, 3], [7, 7]
// [1, 3], [6, 7]
//
//
// Follow up:
// What if there are lots of merges and the number of disjoint intervals are small compared to the data stream's size?
//
//
// Credits:Special thanks to @yunhong for adding this problem and creating most of the test cases.


/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
 struct Cmp {
    bool operator()(Interval a, Interval b){ return a.start < b.start; }
 };
 
class SummaryRanges {
private:
    set<Interval, Cmp> bst;
    
public:
    /** Initialize your data structure here. */
    SummaryRanges() {
        
    }
    
    void addNum(int val) {
        Interval ni(val, val);
        if (bst.size() == 0) {
            bst.insert(ni);
            return;
        }
        auto it = bst.lower_bound(ni);
        if (it->start == val) return;
        if (it == bst.begin()) {
            if (val <= it->end && val >= it->start) return;
            if (val == it->start - 1) {
                Interval nni(val, it->end);
                bst.erase(it);
                bst.insert(nni);
            }
            else {
                bst.insert(ni);
            }
        }
        else {
            it--;
            int nb, ne;
            if (it->end >= val) return;
            if (it->end == val - 1) {
                nb = it->start;
                bst.erase(it);
            }
            else
                nb = val;
            it = bst.lower_bound(ni);
            if (it->start == val + 1) {
                ne = it->end;
                bst.erase(it);
            }
            else
                ne = val;
            Interval nni(nb, ne);
            bst.insert(nni);
        }
    }
    
    vector<Interval> getIntervals() {
        vector<Interval> vi;
        for (Interval i : bst)
            vi.push_back(i);
        return vi;
    }
};

/**
 * Your SummaryRanges object will be instantiated and called as such:
 * SummaryRanges obj = new SummaryRanges();
 * obj.addNum(val);
 * vector<Interval> param_2 = obj.getIntervals();
 */
