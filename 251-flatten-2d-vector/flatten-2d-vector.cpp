// Implement an iterator to flatten a 2d vector.
//
// Example:
//
//
// Input: 2d vector =
// [
//   [1,2],
//   [3],
//   [4,5,6]
// ]
// Output: [1,2,3,4,5,6]
// Explanation: By calling next repeatedly until hasNext returns false, 
//              the order of elements returned by next should be: [1,2,3,4,5,6].
//
// Follow up:
// As an added challenge, try to code it using only iterators in C++ or iterators in Java.
//


class Vector2D {
private:
    vector<vector<int>>::iterator outer_it;
    vector<vector<int>>::iterator outer_end;
    vector<int>::iterator inner_it;
    vector<int>::iterator inner_end;
    
    void goon() {
        if (!hasNext()) return;
        while (inner_it == inner_end) {
            outer_it++;
            if (outer_it == outer_end) break;
            inner_it = (*outer_it).begin();
            inner_end = (*outer_it).end();
        }
    }
    
public:
    Vector2D(vector<vector<int>>& vec2d) {
        outer_end = vec2d.end();
        outer_it = vec2d.begin();
        if (outer_end != outer_it) {
            inner_it = (*outer_it).begin();
            inner_end = (*outer_it).end();
        }
        goon();
    }

    int next() {
        int res = *inner_it;
        inner_it++;
        goon();
        return res;
    }

    bool hasNext() {
        return outer_end != outer_it;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D i(vec2d);
 * while (i.hasNext()) cout << i.next();
 */
