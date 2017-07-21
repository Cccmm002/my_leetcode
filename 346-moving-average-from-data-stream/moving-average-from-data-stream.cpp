// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// For example,
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3


class MovingAverage {
private:
    queue<int> q;
    int len;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        len = size;
        q.empty();
    }
    
    double next(int val) {
        if (q.size() >= len)
            q.pop();
        q.push(val);
        int s = q.size();
        double sum = 0;
        for (int i = 0; i < s; i++) {
            int cur = q.front();
            sum += (double)cur;
            q.pop();
            q.push(cur);
        }
        return sum/s;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
