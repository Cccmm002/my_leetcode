// Given two non-negative integers num1 and num2 represented as string, return the sum of num1 and num2.
//
// Note:
//
// The length of both num1 and num2 is < 5100.
// Both num1 and num2 contains only digits 0-9.
// Both num1 and num2 does not contain any leading zero.
// You must not use any built-in BigInteger library or convert the inputs to integer directly.


class Solution {
public:
    string addStrings(string num1, string num2) {
        int l1 = num1.size();
        int l2 = num2.size();
        int p1 = l1 - 1;
        int p2 = l2 - 1;
        int inc = 0;
        string res = "";
        while (p1 >=0 || p2 >= 0) {
            int i1 = p1 >= 0 ? num1[p1] - '0' : 0;
            int i2 = p2 >= 0 ? num2[p2] - '0' : 0;
            int cur = i1 + i2 + inc;
            if (cur >= 10) {
                inc = 1;
                cur -= 10;
            }
            else
                inc = 0;
            char c = '0' + cur;
            string ss = "0";
            ss[0] = c;
            res = ss + res;
            if (p1 >= 0) p1--;
            if (p2 >= 0) p2--;
        }
        if (inc != 0) res = "1" + res;
        return res;
    }
};
