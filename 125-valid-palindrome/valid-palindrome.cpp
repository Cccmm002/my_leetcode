// Given a string, determine if it is a palindrome, considering only alphanumeric characters and ignoring cases.
//
// Note: For the purpose of this problem, we define empty string as valid palindrome.
//
// Example 1:
//
//
// Input: "A man, a plan, a canal: Panama"
// Output: true
//
//
// Example 2:
//
//
// Input: "race a car"
// Output: false
//
//


class Solution {
private:
    inline bool check(char a, char b) {
        int x, y;
        if (a >= 'A' && a <= 'Z') x = a - 'A';
        if (a >= 'a' && a <= 'z') x = a - 'a';
        if (a >= '0' && a <= '9') x = -1 - a + '0';
        if (b >= 'A' && b <= 'Z') y = b - 'A';
        if (b >= 'a' && b <= 'z') y = b - 'a';
        if (b >= '0' && b <= '9') y = -1 - b + '0';
        return x == y;
    }
    
public:
    bool isPalindrome(string s) {
        int x = 0;
        int y = s.size() - 1;
        while (x <= y) {
            while (!((s[x] >= 'A' && s[x] <= 'Z') || (s[x] >= 'a' && s[x] <= 'z') || (s[x] >= '0' && s[x] <= '9'))) x++;
            while (!((s[y] >= 'A' && s[y] <= 'Z') || (s[y] >= 'a' && s[y] <= 'z') || (s[y] >= '0' && s[y] <= '9'))) y--;
            if (x > y) break;
            if (!check(s[x], s[y])) return false;
            x++;
            y--;
        }
        return true;
    }
};
