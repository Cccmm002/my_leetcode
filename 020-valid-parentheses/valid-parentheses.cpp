// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// An input string is valid if:
//
//
// 	Open brackets must be closed by the same type of brackets.
// 	Open brackets must be closed in the correct order.
//
//
// Note that an empty string is also considered valid.
//
// Example 1:
//
//
// Input: "()"
// Output: true
//
//
// Example 2:
//
//
// Input: "()[]{}"
// Output: true
//
//
// Example 3:
//
//
// Input: "(]"
// Output: false
//
//
// Example 4:
//
//
// Input: "([)]"
// Output: false
//
//
// Example 5:
//
//
// Input: "{[]}"
// Output: true
//
//


class Solution {
public:
    bool isValid(string s) {
        int len=s.length();
        if(len==0) return 0;
        stack<char> st;
        char c;
        for(int i=0;i<len;i++){
            switch (s[i]){
            case '(': st.push('('); break;
            case '{': st.push('{'); break;
            case '[': st.push('['); break;
            case ')':
                if(st.size()==0) return false;
                c=st.top();
                st.pop();
                if(c!='(') return false;
                break;
            case ']':
                if(st.size()==0) return false;
                c=st.top();
                st.pop();
                if(c!='[') return false;
                break;
            case '}':
                if(st.size()==0) return false;
                c=st.top();
                st.pop();
                if(c!='{') return false;
                break;
            }
        }
        if(st.size()==0) return true;
        else return false;
    }
};
