// Implement a basic calculator to evaluate a simple expression string.
//
// The expression string may contain open ( and closing parentheses ), the plus + or minus sign -, non-negative integers and empty spaces  .
//
// The expression string contains only non-negative integers, +, -, *, / operators , open ( and closing parentheses ) and empty spaces  . The integer division should truncate toward zero.
//
// You may assume that the given expression is always valid. All intermediate results will be in the range of [-2147483648, 2147483647].
//
// Some examples:
//
//
// "1 + 1" = 2
// " 6-4 / 2 " = 4
// "2*(5+5*2)/3+(6/2+8)" = 21
// "(2+6* 3+5- (3*14/7+2)*5)+3"=-12
//
//
//  
//
// Note: Do not use the eval built-in library function.
//


class Solution {
    public int calculate(String s) {
        s += "+";
        int n = s.length();
        int res = 0, term = 0, num = 0;
        char op = '+';
        Stack<StackContent> stack = new Stack<>();
        for (int i = 0; i <= n; i++) {
            if (i >= n) {
                res += term;
                break;
            }
            char c = s.charAt(i);
            if (c == ' ')
                continue;
            if (Character.isDigit(c)) {
                int digit = Character.digit(c, 10);
                num = num*10 + digit;
            }
            else {
                if (c == '(') {
                    stack.push(new StackContent(res, term, op));
                    res = 0;
                    term = 0;
                    num = 0;
                    op = '+';
                    continue;
                }
                if (op == '+') {
                    res += term;
                    term = num;
                }
                else if (op == '-') {
                    res += term;
                    term = -num;
                }
                else if (op == '*') {
                    term *= num;
                }
                else if (op == '/') {
                    term /= num;
                }
                num = 0;
                if (c == '+' || c == '-' || c == '*' || c == '/')
                    op = c;
                if (c == ')') {
                    res += term;
                    StackContent sc = stack.pop();
                    num = res;
                    res = sc.res;
                    term = sc.term;
                    op = sc.op;
                }
            }
        }
        return res;
    }
}

class StackContent {
    public int res;
    public int term;
    public char op;
    
    StackContent(int _res, int _term, char _op) {
        this.res = _res;
        this.term = _term;
        this.op = _op;
    }
}
