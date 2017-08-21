// There is a strange printer with the following two special requirements:
//
//
// The printer can only print a sequence of the same character each time.
// At each turn, the printer can print new characters starting from and ending at any places, and will cover the original existing characters.
//
//
//
//
//
// Given a string consists of lower English letters only, your job is to count the minimum number of turns the printer needed in order to print it.
//
//
// Example 1:
//
// Input: "aaabbb"
// Output: 2
// Explanation: Print "aaa" first and then print "bbb".
//
//
//
// Example 2:
//
// Input: "aba"
// Output: 2
// Explanation: Print "aaa" first and then print "b" from the second place of the string, which will cover the existing character 'a'.
//
//
//
// Hint: Length of the given string will not exceed 100.


public class Solution {
    private int calc(int i, int j ,int k, int[,,] arr, string s) {
        if (i > j) return 0;
        if (i == j) return 1;
        if (arr[i,j,k] >= 0) return arr[i,j,k];
        while (i < j && s[i] == s[i + 1]) {
            i++;
            k++;
        }
        int res = 1 + calc(i + 1, j, 0, arr, s);
        for (int m = i + 1; m <= j; m++) {
            if (s[i] != s[m]) continue;
            int cur = calc(i + 1, m - 1, 0, arr, s) + calc(m, j, k + 1, arr, s);
            res = Math.Min(res, cur);
        }
        arr[i,j,k] = res;
        return res;
    }
    
    public int StrangePrinter(string s) {
        int n = s.Length;
        if (n == 0) return 0;
        int[,,] arr = new int[n, n, n];
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) arr[i,j,k] = -1;
            }
        }
        int res = calc(0, n - 1, 0, arr, s);
        return res;
    }
}
