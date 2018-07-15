// The API: int read4(char *buf) reads 4 characters at a time from a file.
//
// The return value is the actual number of characters read. For example, it returns 3 if there is only 3 characters left in the file.
//
// By using the read4 API, implement the function int read(char *buf, int n) that reads n characters from the file.
//
// Note:
// The read function may be called multiple times.
//
// Example 1: 
//
//
// Given buf = "abc"
// read("abc", 1) // returns "a"
// read("abc", 2); // returns "bc"
// read("abc", 1); // returns ""
//
//
// Example 2: 
//
//
// Given buf = "abc"
// read("abc", 4) // returns "abc"
// read("abc", 1); // returns ""
//
//


// Forward declaration of the read4 API.
int read4(char *buf);

class Solution {
private:
    char buffer[4];
    int bufPointer;
    int contentPointer;
    int effBuf;
    bool finished;
    
public:
    Solution() {
        bufPointer = 0;
        contentPointer = 0;
        effBuf = 0;
        finished = false;
    }
    
    /**
     * @param buf Destination buffer
     * @param n   Maximum number of characters to read
     * @return    The number of characters read
     */
    int read(char *buf, int n) {
        int cur = 0;
        while (cur < n) {
            if (bufPointer < effBuf) {
                buf[cur] = buffer[bufPointer];
                contentPointer++;
                bufPointer++;
                cur++;
            }
            else {
                if (finished) break;
                int nextRead = read4(buffer);
                if (nextRead < 4) finished = true;
                effBuf = nextRead;
                bufPointer = 0;
            }
        }
        return cur;
    }
};
