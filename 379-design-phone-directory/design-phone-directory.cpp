// Design a Phone Directory which supports the following operations:
//
//
//
// get: Provide a number which is not assigned to anyone.
// check: Check if a number is available or not.
// release: Recycle or release a number.
//
//
//
// Example:
//
// // Init a phone directory containing a total of 3 numbers: 0, 1, and 2.
// PhoneDirectory directory = new PhoneDirectory(3);
//
// // It can return any available phone number. Here we assume it returns 0.
// directory.get();
//
// // Assume it returns 1.
// directory.get();
//
// // The number 2 is available, so return true.
// directory.check(2);
//
// // It returns 2, the only number that is left.
// directory.get();
//
// // The number 2 is no longer available, so return false.
// directory.check(2);
//
// // Release number 2 back to the pool.
// directory.release(2);
//
// // Number 2 is available again, return true.
// directory.check(2);
//
//


class PhoneDirectory {
private:
    bool *pool;
    int n;
    int next;
    
public:
    /** Initialize your data structure here
        @param maxNumbers - The maximum numbers that can be stored in the phone directory. */
    PhoneDirectory(int maxNumbers) {
        pool = (bool*)malloc(sizeof(bool) * maxNumbers);
        for (int i = 0; i < maxNumbers; i++) pool[i] = true;
        n = maxNumbers;
        next = 0;
    }
    
    /** Provide a number which is not assigned to anyone.
        @return - Return an available number. Return -1 if none is available. */
    int get() {
        if (next == -1) return -1;
        else {
            int res = next;
            bool found = false;
            for (int i = next + 1; i < n; i++) {
                if (pool[i]) {
                    next = i;
                    found = true;
                    break;
                }
            }
            if (!found) next = -1;
            pool[res] = false;
            return res;
        }
    }
    
    /** Check if a number is available or not. */
    bool check(int number) {
        return pool[number];
    }
    
    /** Recycle or release a number. */
    void release(int number) {
        pool[number] = true;
        if (next == -1) next = number;
        else next = min(next, number);
    }
    
    ~PhoneDirectory() {
        delete pool;
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj.get();
 * bool param_2 = obj.check(number);
 * obj.release(number);
 */
