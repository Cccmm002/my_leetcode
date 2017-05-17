// Given a string containing just the characters '(' and ')', find the length of the longest valid (well-formed) parentheses substring.
//
//
// For "(()", the longest valid parentheses substring is "()", which has length = 2.
//
//
// Another example is ")()())", where the longest valid parentheses substring is "()()", which has length = 4.


class Solution {
public:
    int longestValidParentheses(string s) {
        int len = s.length();
        int *arr = (int*)malloc(sizeof(int)*len);
        memset(arr, 0, sizeof(int)*len);
        stack<int> st;
        int res = 0;
        for(int i=0;i<len;i++) {
            if(s[i] == '(') {
                st.push(i);
            }
            else {
                if(st.empty()) continue;
                int t = st.top();
                st.pop();
                arr[i] = i - t + 1;
                if(t != 0)
                    arr[i] += arr[t - 1];
                res = arr[i]>res?arr[i]:res;
            }
        }
        free(arr);
        return res;
    }
};
