// Median is the middle value in an ordered integer list. If the size of the list is even, there is no middle value. So the median is the mean of the two middle value.
// For example,
//
// [2,3,4], the median is 3
//
// [2,3], the median is (2 + 3) / 2 = 2.5
//
// Design a data structure that supports the following two operations:
//
//
// 	void addNum(int num) - Add a integer number from the data stream to the data structure.
// 	double findMedian() - Return the median of all elements so far.
//
//
// Example:
//
//
// addNum(1)
// addNum(2)
// findMedian() -> 1.5
// addNum(3) 
// findMedian() -> 2
//
//


class MedianFinder {
private:
    priority_queue<int> smaller;
    std::priority_queue<int, vector<int>, greater<int>> larger;
    
public:
    /** initialize your data structure here. */
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        if (num < findMedian()) {
            smaller.push(num);
            if (smaller.size() > larger.size() + 1) {
                larger.push(smaller.top());
                smaller.pop();
            }
        }
        else {
            larger.push(num);
            if (larger.size() > smaller.size() + 1) {
                smaller.push(larger.top());
                larger.pop();
            }
        }
    }
    
    double findMedian() {
        if (smaller.size() == 0 && larger.size() == 0)
            return 0;
        if (smaller.size() == larger.size()) {
            return ((double)smaller.top()+(double)larger.top())/2.0;
        }
        else if(smaller.size() > larger.size()) {
            return smaller.top();
        }
        else {
            return larger.top();
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder obj = new MedianFinder();
 * obj.addNum(num);
 * double param_2 = obj.findMedian();
 */
