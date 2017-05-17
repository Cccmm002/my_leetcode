// Evaluate the value of an arithmetic expression in Reverse Polish Notation.
//
//
//
// Valid operators are +, -, *, /. Each operand may be an integer or another expression.
//
//
//
// Some examples:
//
//   ["2", "1", "+", "3", "*"] -> ((2 + 1) * 3) -> 9
//   ["4", "13", "5", "/", "+"] -> (4 + (13 / 5)) -> 6


class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len=tokens.size();
        stack<int> s;
        for(int i=0;i<len;i++){
            string t=tokens[i];
            if(t!="+"&&t!="-"&&t!="*"&&t!="/"){
                s.push(stoi(t));
                continue;
            }
            int b=s.top();
            s.pop();
            int a=s.top();
            s.pop();
            if(t=="+")
                s.push(a+b);
            else if(t=="-")
                s.push(a-b);
            else if(t=="*")
                s.push(a*b);
            else if(t=="/")
                s.push(a/b);
        }
        return s.top();
    }
};
