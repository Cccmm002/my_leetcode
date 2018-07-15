// Given a stream of integers and a window size, calculate the moving average of all integers in the sliding window.
//
// For example,
//
// MovingAverage m = new MovingAverage(3);
// m.next(1) = 1
// m.next(10) = (1 + 10) / 2
// m.next(3) = (1 + 10 + 3) / 3
// m.next(5) = (10 + 3 + 5) / 3
//
//


class MovingAverage {
private:
    int *arr;
    int length;
    int pointer;
    int sum;
    int count;
    
public:
    /** Initialize your data structure here. */
    MovingAverage(int size) {
        arr = new int[size];
        length = size;
        pointer = 0;
        sum = 0;
        count = 0;
        for (int i = 0; i < length; i++)
            arr[i] = 0;
    }
    
    double next(int val) {
        sum -= arr[pointer];
        sum += val;
        arr[pointer] = val;
        ++pointer;
        if (count < length) ++count;
        if (pointer >= length)
            pointer = 0;
        return ((double)sum)/((double)count);
    }
    
    ~MovingAverage() {
        delete[] arr;
    }
};

/**
 * Your MovingAverage object will be instantiated and called as such:
 * MovingAverage obj = new MovingAverage(size);
 * double param_1 = obj.next(val);
 */
