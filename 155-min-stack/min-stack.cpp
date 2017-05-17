// Design a stack that supports push, pop, top, and retrieving the minimum element in constant time.
//
//
// push(x) -- Push element x onto stack.
//
//
// pop() -- Removes the element on top of the stack.
//
//
// top() -- Get the top element.
//
//
// getMin() -- Retrieve the minimum element in the stack.
//
//
//
//
// Example:
//
// MinStack minStack = new MinStack();
// minStack.push(-2);
// minStack.push(0);
// minStack.push(-3);
// minStack.getMin();   --> Returns -3.
// minStack.pop();
// minStack.top();      --> Returns 0.
// minStack.getMin();   --> Returns -2.


class MinStack {
private:
    vector<int> v;
    int min;
public:
    /** initialize your data structure here. */
    MinStack() {
        v.clear();
        min=INT_MAX;
    }
    
    void push(int x) {
        if(x<=min) {
            v.push_back(min);
            min=x;
        }
        v.push_back(x);
    }
    
    void pop() {
        if(v.size()<=0) return;
        auto it=v.end()-1;
        if(*it==min){
            v.erase(it);
            it--;
            min=*it;
        }
        v.erase(it);
    }
    
    int top() {
        return v[v.size()-1];
    }
    
    int getMin() {
        return min;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack obj = new MinStack();
 * obj.push(x);
 * obj.pop();
 * int param_3 = obj.top();
 * int param_4 = obj.getMin();
 */
