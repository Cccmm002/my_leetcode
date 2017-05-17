// Given a roman numeral, convert it to an integer.
//
// Input is guaranteed to be within the range from 1 to 3999.


class Solution {
public:
    inline int getNum(char c){
    if(c=='I')
        return 1;
    if(c=='V')
        return 5;
    if(c=='X')
        return 10;
    if(c=='L')
        return 50;
    if(c=='C')
        return 100;
    if(c=='D')
        return 500;
    if(c=='M')
        return 1000;
    else
        return 0;
}

int romanToInt(string s) {
    int length=s.length();
    if(length==0)
        return 0;
    if(length==1)
        return getNum(s[0]);
    else if(getNum(s[0])<getNum(s[1]))
        return getNum(s[1])-getNum(s[0])+romanToInt(s.substr(2,length-2));
    else
        return getNum(s[0])+romanToInt(s.substr(1,length-1));
}
};
