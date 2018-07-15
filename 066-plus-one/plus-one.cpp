// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//


class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n = digits.size();
        vector<int> v(n);
        int flag = 1;
        for (int i = 0; i < n; i++) {
            int s = digits[n - i - 1] + flag;
            v[i] = s%10;
            flag = s / 10;
        }
        if (flag > 0) v.push_back(1);
        vector<int> res;
        for (int i = v.size() - 1; i >= 0; i--) {
            res.push_back(v[i]);
        }
        return res;
    }
};
