// Given an input string, reverse the string word by word.
//
// Example:  
//
//
// Input: "the sky is blue",
// Output: "blue is sky the".
//
//
// Note:
//
//
// 	A word is defined as a sequence of non-space characters.
// 	Input string may contain leading or trailing spaces. However, your reversed string should not contain leading or trailing spaces.
// 	You need to reduce multiple spaces between two words to a single space in the reversed string.
//
//
// Follow up: For C programmers, try to solve it in-place in O(1) space.
//


class Solution {
public:
    void reverseWords(string &s) {
        string res="";
        int end=s.length()-1;
        while(end>=0) {
            while(s[end]==' ') end--;
            if(end<0) break;
            int begin=end;
            while(begin>=0 && s[begin]!=' ') begin--;
            res+=s.substr(begin+1,end-begin);
            res+=' ';
            end=begin;
        }
        s=res.substr(0,res.length()-1);
    }
};
