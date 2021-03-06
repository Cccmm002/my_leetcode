// We have a string S of lowercase letters, and an integer array shifts.
//
// Call the shift of a letter, the next letter in the alphabet, (wrapping around so that 'z' becomes 'a'). 
//
// For example, shift('a') = 'b', shift('t') = 'u', and shift('z') = 'a'.
//
// Now for each shifts[i] = x, we want to shift the first i+1 letters of S, x times.
//
// Return the final string after all such shifts to S are applied.
//
// Example 1:
//
//
// Input: S = "abc", shifts = [3,5,9]
// Output: "rpl"
// Explanation: 
// We start with "abc".
// After shifting the first 1 letters of S by 3, we have "dbc".
// After shifting the first 2 letters of S by 5, we have "igc".
// After shifting the first 3 letters of S by 9, we have "rpl", the answer.
//
//
// Note:
//
//
// 	1 <= S.length = shifts.length <= 20000
// 	0 <= shifts[i] <= 10 ^ 9
//


class Solution {
    public String shiftingLetters(String S, int[] shifts) {
        int n = shifts.length;
        long[] sums = new long[n];
        long cur = 0;
        for (int i = n - 1; i >= 0; i--) {
            sums[i] = cur + (long)shifts[i];
            cur = sums[i];
        }
        StringBuilder sb = new StringBuilder(S);
        for (int i = 0; i < n; i++) {
            char c = sb.charAt(i);
            long ascii = (long)c - 97;
            ascii = (ascii + sums[i])%26;
            sb.setCharAt(i, (char)(ascii + 97));
        }
        return sb.toString();
    }
}
