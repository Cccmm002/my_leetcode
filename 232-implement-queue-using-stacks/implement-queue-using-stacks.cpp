// Implement the following operations of a queue using stacks.
//
//
// push(x) -- Push element x to the back of queue.
//
//
// pop() -- Removes the element from in front of queue.
//
//
// peek() -- Get the front element.
//
//
// empty() -- Return whether the queue is empty.
//
//
// Notes:
//
// You must use only standard operations of a stack -- which means only push to top, peek/pop from top, size, and is empty operations are valid.
// Depending on your language, stack may not be supported natively. You may simulate a stack by using a list or deque (double-ended queue), as long as you use only standard operations of a stack.
// You may assume that all operations are valid (for example, no pop or peek operations will be called on an empty queue).


class Queue {
private:
    stack<int> in,out;
    
    void select() {
        if(!out.empty()) return;
        int ss=in.size();
        for(int i=0;i<ss;i++){
            out.push(in.top());
            in.pop();
        }
    }
public:
    // Push element x to the back of queue.
    void push(int x) {
        in.push(x);
    }

    // Removes the element from in front of queue.
    void pop(void) {
        select();
        out.pop();
    }

    // Get the front element.
    int peek(void) {
        select();
        return out.top();
    }

    // Return whether the queue is empty.
    bool empty(void) {
        return in.empty() && out.empty();
    }
};
