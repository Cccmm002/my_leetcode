// Given two strings A and B of lowercase letters, return true if and only if we can swap two letters in A so that the result equals B.
//
//  
//
// Example 1:
//
//
//
// Input: A = "ab", B = "ba"
// Output: true
//
//
//
// Example 2:
//
//
// Input: A = "ab", B = "ab"
// Output: false
//
//
//
// Example 3:
//
//
// Input: A = "aa", B = "aa"
// Output: true
//
//
//
// Example 4:
//
//
// Input: A = "aaaaaaabc", B = "aaaaaaacb"
// Output: true
//
//
//
// Example 5:
//
//
// Input: A = "", B = "aa"
// Output: false
//
//
//  
//
// Note:
//
//
// 	0 <= A.length <= 20000
// 	0 <= B.length <= 20000
// 	A and B consist only of lowercase letters.
//
//
//
//
//
//
//


class Solution {
    public boolean buddyStrings(String A, String B) {
        int n1 = A.length();
        int n2 = B.length();
        if (n1 != n2)
            return false;
        if (n1 == 0)
            return false;
        if (A.equals(B)) {
            Set<Character> s = new HashSet<Character>();
            for (int i = 0; i < n1; i++)
                s.add(A.charAt(i));
            return s.size() < n1;
        }
        int[] pos = new int[2];
        int index = 0;
        for (int i = 0; i < n1; i++) {
            if (A.charAt(i) != B.charAt(i)) {
                if (index >= 2)
                    return false;
                pos[index] = i;
                index++;
            }
        }
        if (index == 1)
            return false;
        if (A.charAt(pos[0]) != B.charAt(pos[1]))
            return false;
        if (A.charAt(pos[1]) != B.charAt(pos[0]))
            return false;
        return true;
    }
}
