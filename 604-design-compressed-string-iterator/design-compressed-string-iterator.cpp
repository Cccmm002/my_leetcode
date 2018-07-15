//
// Design and implement a data structure for a compressed string iterator. It should support the following operations: next and hasNext.
//
//
//
// The given compressed string will be in the form of each letter followed by a positive integer representing the number of this letter existing in the original uncompressed string.
//
//
//
// next() - if the original string still has uncompressed characters, return the next letter; Otherwise return a white space.
// hasNext() - Judge whether there is any letter needs to be uncompressed.
//
//
//
// Note:
// Please remember to RESET your class variables declared in StringIterator, as static/class variables are persisted across multiple test cases. Please see here for more details.
//
//
//
// Example:
//
// StringIterator iterator = new StringIterator("L1e2t1C1o1d1e1");
//
// iterator.next(); // return 'L'
// iterator.next(); // return 'e'
// iterator.next(); // return 'e'
// iterator.next(); // return 't'
// iterator.next(); // return 'C'
// iterator.next(); // return 'o'
// iterator.next(); // return 'd'
// iterator.hasNext(); // return true
// iterator.next(); // return 'e'
// iterator.hasNext(); // return false
// iterator.next(); // return ' '
//
//


class StringIterator {
private:
    string str;
    int pointer;
    int cap, count;
    char current;
    
    void move() {
        if (pointer >= str.size()) return;
        current = str[pointer];
        int r = pointer + 1;
        while (r < str.size() && str[r] <= '9' && str[r] >= '0')
            r++;
        cap = stoi(str.substr(pointer + 1, r - pointer - 1));
        count = 0;
        pointer = r;
    }
    
public:
    StringIterator(string compressedString) {
        str = compressedString;
        pointer = 0;
        move();
    }
    
    char next() {
        if (!hasNext()) return ' ';
        char res = current;
        count++;
        if (count >= cap)
            move();
        return res;
    }
    
    bool hasNext() {
        if (count < cap) return true;
        return pointer < str.size();
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator obj = new StringIterator(compressedString);
 * char param_1 = obj.next();
 * bool param_2 = obj.hasNext();
 */
