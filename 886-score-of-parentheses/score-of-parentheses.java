// Given a balanced parentheses string S, compute the score of the string based on the following rule:
//
//
// 	() has score 1
// 	AB has score A + B, where A and B are balanced parentheses strings.
// 	(A) has score 2 * A, where A is a balanced parentheses string.
//
//
//  
//
//
// Example 1:
//
//
// Input: "()"
// Output: 1
//
//
//
// Example 2:
//
//
// Input: "(())"
// Output: 2
//
//
//
// Example 3:
//
//
// Input: "()()"
// Output: 2
//
//
//
// Example 4:
//
//
// Input: "(()(()))"
// Output: 6
//
//
//  
//
// Note:
//
//
// 	S is a balanced parentheses string, containing only ( and ).
// 	2 <= S.length <= 50
//
//
//
//
//


class Solution {
    public int scoreOfParentheses(String S) {
        int n = S.length();
        Stack<Integer> stack = new Stack<Integer>();
        stack.push(0);
        for (int i = 0; i < n; i++) {
            char c = S.charAt(i);
            if (c == '(') {
                stack.push(0);
            }
            else {
                int cur = stack.pop();
                if (cur == 0) 
                    cur = 1;
                else
                    cur = cur * 2;
                int prev = stack.pop();
                stack.push(prev + cur);
            }
        }
        return stack.pop();
    }
}
