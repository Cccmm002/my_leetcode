// Given a non-negative integer c, your task is to decide whether there're two integers a and b such that a2 + b2 = c.
//
//
// Example 1:
//
// Input: 5
// Output: True
// Explanation: 1 * 1 + 2 * 2 = 5
//
//
//
//
// Example 2:
//
// Input: 3
// Output: False


class Solution {
public:
    bool judgeSquareSum(int c) {
        unordered_set<int> uset;
        int limit = sqrt(c);
        for (int i = 0; i <= limit; ++i) {
            uset.insert(i*i);
        }
        for (int i = 0; i <= limit; ++i) {
            int check = c - i*i;
            if (uset.find(check) != uset.end())
                return true;
        }
        return false;
    }
};
