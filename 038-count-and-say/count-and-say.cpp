// The count-and-say sequence is the sequence of integers beginning as follows:
// 1, 11, 21, 1211, 111221, ...
//
//
//
// 1 is read off as "one 1" or 11.
// 11 is read off as "two 1s" or 21.
// 21 is read off as "one 2, then one 1" or 1211.
//
//
//
// Given an integer n, generate the nth sequence.
//
//
//
// Note: The sequence of integers will be represented as a string.


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
