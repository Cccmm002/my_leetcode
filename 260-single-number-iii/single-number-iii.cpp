// Given an array of numbers nums, in which exactly two elements appear only once and all the other elements appear exactly twice. Find the two elements that appear only once.
//
//
// For example:
//
//
// Given nums = [1, 2, 1, 3, 2, 5], return [3, 5].
//
//
// Note:
//
// The order of the result is not important. So in the above example, [5, 3] is also correct.
// Your algorithm should run in linear runtime complexity. Could you implement it using only constant space complexity?
//
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        int first = 0;
        for (int n : nums) first = first ^ n;
        int d = 0;
        while ((first & 1) == 0) {
            ++d;
            first = first >> 1;
        }
        int mask = (1 << d);
        int a = 0;
        int b = 0;
        for (int n : nums) {
            if ((mask & n) == 0) a = a^n;
            else b = b^n;
        }
        vector<int> res = {a, b};
        return res;
    }
};
