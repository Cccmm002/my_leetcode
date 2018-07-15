// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
//
// Write a function to determine if a number is strobogrammatic. The number is represented as a string.
//
// Example 1:
//
//
// Input:  "69"
// Output: true
//
//
// Example 2:
//
//
// Input:  "88"
// Output: true
//
// Example 3:
//
//
// Input:  "962"
// Output: false
//


class Solution {
public:
    bool isStrobogrammatic(string num) {
        int len = num.size();
        int begin = 0;
        int end = len - 1;
        for (; begin < end; begin++, end--) {
            if (num[begin] == '1') {
                if (num[end] == '1') continue;
                else return false;
            }
            if (num[begin] == '0') {
                if (num[end] == '0') continue;
                else return false;
            }
            if (num[begin] == '8') {
                if (num[end] == '8') continue;
                else return false;
            }
            if (num[begin] == '6') {
                if (num[end] == '9') continue;
                else return false;
            }
            if (num[begin] == '9') {
                if (num[end] == '6') continue;
                else return false;
            }
            return false;
        }
        if (begin == end) {
            if (num[begin] != '1' && num[begin] != '0' && num[begin] != '8') return false;
        }
        return true;
    }
};
