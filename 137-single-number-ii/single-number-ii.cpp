// Given a non-empty array of integers, every element appears three times except for one, which appears exactly once. Find that single one.
//
// Note:
//
// Your algorithm should have a linear runtime complexity. Could you implement it without using extra memory?
//
// Example 1:
//
//
// Input: [2,2,3,2]
// Output: 3
//
//
// Example 2:
//
//
// Input: [0,1,0,1,0,1,99]
// Output: 99
//


class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < sizeof(int)*8; i++) {
            int count = 0;
            for (int n : nums) {
                count += ((n >> i) & 1);
            }
            int cur = count %3;
            res += (cur << i);
        }
        return res;
    }
};
