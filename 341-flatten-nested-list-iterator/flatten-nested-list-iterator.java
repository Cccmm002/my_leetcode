// Given a nested list of integers, implement an iterator to flatten it.
//
// Each element is either an integer, or a list -- whose elements may also be integers or other lists.
//
// Example 1:
// Given the list [[1,1],2,[1,1]],
//
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,1,2,1,1].
//
//
//
// Example 2:
// Given the list [1,[4,[6]]],
//
// By calling next repeatedly until hasNext returns false, the order of elements returned by next should be: [1,4,6].


/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * public interface NestedInteger {
 *
 *     // @return true if this NestedInteger holds a single integer, rather than a nested list.
 *     public boolean isInteger();
 *
 *     // @return the single integer that this NestedInteger holds, if it holds a single integer
 *     // Return null if this NestedInteger holds a nested list
 *     public Integer getInteger();
 *
 *     // @return the nested list that this NestedInteger holds, if it holds a nested list
 *     // Return null if this NestedInteger holds a single integer
 *     public List<NestedInteger> getList();
 * }
 */
public class NestedIterator implements Iterator<Integer> {
    
    private Stack<List<NestedInteger>> stack;
    private Stack<Integer> pointers;

    public NestedIterator(List<NestedInteger> nestedList) {
        stack = new Stack<List<NestedInteger>>();
        pointers = new Stack<Integer>();
        stack.push(nestedList);
        pointers.push(0);
    }

    @Override
    public Integer next() {
        int res = stack.peek().get(pointers.peek()).getInteger();
        int cur = pointers.pop();
        pointers.push(cur + 1);
        return res;
    }

    @Override
    public boolean hasNext() {
        while(pointers.peek() == stack.peek().size()) {
            stack.pop();
            pointers.pop();
            if(pointers.size() == 0)
                return false;
            int cur = pointers.pop();
            pointers.push(cur + 1);
        }
        while(!stack.peek().get(pointers.peek()).isInteger()) {
            List<NestedInteger> cl = stack.peek().get(pointers.peek()).getList();
            if(cl.size() == 0) {
                int cur = pointers.pop();
                pointers.push(cur + 1);
                return hasNext();
            }
            else {
                stack.push(cl);
                pointers.push(0);
            }
        }
        return true;
    }
}

/**
 * Your NestedIterator object will be instantiated and called as such:
 * NestedIterator i = new NestedIterator(nestedList);
 * while (i.hasNext()) v[f()] = i.next();
 */
