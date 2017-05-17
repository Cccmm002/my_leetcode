// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.
//
// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.


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
