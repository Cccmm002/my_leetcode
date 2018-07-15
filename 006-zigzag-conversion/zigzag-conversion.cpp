// The string "PAYPALISHIRING" is written in a zigzag pattern on a given number of rows like this: (you may want to display this pattern in a fixed font for better legibility)
//
//
// P   A   H   N
// A P L S I I G
// Y   I   R
//
//
// And then read line by line: "PAHNAPLSIIGYIR"
//
// Write the code that will take a string and make this conversion given a number of rows:
//
//
// string convert(string s, int numRows);
//
// Example 1:
//
//
// Input: s = "PAYPALISHIRING", numRows = 3
// Output: "PAHNAPLSIIGYIR"
//
//
// Example 2:
//
//
// Input: s = "PAYPALISHIRING", numRows = 4
// Output: "PINALSIGYAHRPI"
// Explanation:
//
// P     I    N
// A   L S  I G
// Y A   H R
// P     I
//


class Solution {
public:
    string convert(string s, int numRows) {
    if(numRows==1)
        return s;
           vector<string> res(numRows,"");
    int row=0,n=0;
    int length=s.length();
    int inverse=0;
    while(n<length){
        res[row].append(s.begin()+n,s.begin()+n+1);
        n++;
        if(inverse==0){
            row++;
            if(row>=numRows){
                row-=2;
                inverse=1;
            }
        }else{
            row--;
            if(row<0){
                row=1;
                inverse=0;
            }
        }
    }
    string sres="";
    for(int i=0;i<numRows;i++)
        sres.append(res[i]);
    return sres; 
    }
};
