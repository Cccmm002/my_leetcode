// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
// Example 1:
//
//
// Input: "(()"
// Output: 2
// Explanation: The longest valid parentheses substring is "()"
//
//
// Example 2:
//
//
// Input: ")()())"
// Output: 4
// Explanation: The longest valid parentheses substring is "()()"
//
//


class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> left_stack;
        left_stack.push(-1);
        int length = s.size();
        int res = 0;
        for (int i = 0; i < length; i++) {
            if (s[i] == '(') {
                left_stack.push(i);
            }
            else {
                left_stack.pop();
                if (left_stack.empty()) {
                    left_stack.push(i);
                }
                else {
                    int current = i - left_stack.top();
                    res = max(res, current);
                }
            }
        }
        return res;
    }
};
