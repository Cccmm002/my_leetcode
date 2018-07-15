// Design a max stack that supports push, pop, top, peekMax and popMax.
//
//
//
// push(x) -- Push element x onto stack.
// pop() -- Remove the element on top of the stack and return it.
// top() -- Get the element on the top.
// peekMax() -- Retrieve the maximum element in the stack.
// popMax() -- Retrieve the maximum element in the stack, and remove it. If you find more than one maximum elements, only remove the top-most one.
//
//
//
// Example 1:
//
// MaxStack stack = new MaxStack();
// stack.push(5); 
// stack.push(1);
// stack.push(5);
// stack.top(); -> 5
// stack.popMax(); -> 5
// stack.top(); -> 1
// stack.peekMax(); -> 5
// stack.pop(); -> 1
// stack.top(); -> 5
//
//
//
// Note:
//
// -1e7 <= x <= 1e7
// Number of operations won't exceed 10000.
// The last four operations won't be called when stack is empty.
//
//


class MaxStack {
private:
    vector<int> v;
    int m;
    int loc;
    
    void findMax() {
        if (v.size() == 0) return;
        m = INT_MIN;
        for (int i = 0; i < v.size(); i++) {
            if (v[i] >= m) {
                m = v[i];
                loc = i;
            }
        }
    }
    
public:
    /** initialize your data structure here. */
    MaxStack() {
        
    }
    
    void push(int x) {
        v.push_back(x);
        if (v.size() == 1) {
            m = x;
            loc = 0;
        }
        if (x >= m) {
            m = x;
            loc = v.size() - 1;
        }
    }
    
    int pop() {
        int s = v.size();
        if (s > 0) {
            int res = v[s - 1];
            v.pop_back();
            if (res == m)
                findMax();
            return res;
        }
        return -1;
    }
    
    int top() {
        int s = v.size();
        if (s > 0) {
            return v[s - 1];
        }
        return -1;
    }
    
    int peekMax() {
        return m;
    }
    
    int popMax() {
        int res = m;
        v.erase(v.begin() + loc);
        findMax();
        return res;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack obj = new MaxStack();
 * obj.push(x);
 * int param_2 = obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.peekMax();
 * int param_5 = obj.popMax();
 */
