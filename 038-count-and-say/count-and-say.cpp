// The count-and-say sequence is the sequence of integers with the first five terms as following:
//
// 1.     1
// 2.     11
// 3.     21
// 4.     1211
// 5.     111221
//
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
//
//
// Given an integer n, generate the nth term of the count-and-say sequence.
//
//
//
// Note: Each term of the sequence of integers will be represented as a string.
//
//
// Example 1:
//
// Input: 1
// Output: "1"
//
//
//
// Example 2:
//
// Input: 4
// Output: "1211"


class Solution {
public:
    string countAndSay(int n) {
        string last="1";
        if(n==1) return last;
        for(int i=1;i<n;i++){
            string curString="";
            int pointer=1;
            int counter=1;
            int curDigit=last[0]-'1'+1;
            while(pointer!=last.length()){
                int cur=last[pointer]-'1'+1;
                if(cur==curDigit)
                    counter++;
                else {
                    curString+=to_string(counter)+to_string(curDigit);
                    curDigit=cur;
                    counter=1;
                }
                pointer++;
            }
            curString+=to_string(counter)+to_string(curDigit);
            last=curString;
        }
        return last;
    }
};
