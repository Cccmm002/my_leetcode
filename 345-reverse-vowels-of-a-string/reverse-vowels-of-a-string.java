// Write a function that takes a string as input and reverse only the vowels of a string.
//
//
// Example 1:
// Given s = "hello", return "holle".
//
//
//
// Example 2:
// Given s = "leetcode", return "leotcede".
//
//
//
// Note:
// The vowels does not include the letter "y".
//


public class Solution {
    public String reverseVowels(String s) {
        Character[] l={'a','e','i','o','u','A','E','I','O','U'};
        ArrayList<Character> alc=new ArrayList<>(Arrays.asList(l));
        int len=s.length();
        char[] r=new char[len];
        int begin=0;
        int end=len-1;
        while(begin<=end) {
            char cb=s.charAt(begin);
            if(!alc.contains(cb)){
                r[begin]=cb;
                begin++;
                continue;
            }
            char ce=s.charAt(end);
            if(!alc.contains(ce)){
                r[end]=ce;
                end--;
                continue;
            }
            r[end]=cb;
            r[begin]=ce;
            begin++;
            end--;
        }
        String res=new String(r);
        return res;
    }
}
