// Write a function that takes a string as input and returns the string reversed.
//
//
// Example:
// Given s = "hello", return "olleh".
//


public class Solution {
    public String reverseString(String s) {
        int len=s.length();
        char[] c=new char[len];
        for(int i=0;i<len;i++)
            c[i]=s.charAt(len-i-1);
        String res=new String(c);
        return res;
    }
}
