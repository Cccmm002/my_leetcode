// Given a sorted integer array without duplicates, return the summary of its ranges.
//
// Example 1:
//
// Input: [0,1,2,4,5,7]
// Output: ["0->2","4->5","7"]
//
//
//
// Example 2:
//
// Input: [0,2,3,4,6,8,9]
// Output: ["0","2->4","6","8->9"]
//
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int len = nums.size();
        vector<string> res;
        if (len == 0) return res;
        if (len == 1) {
            res.push_back(to_string(nums[0]));
            return res;
        }
        int prev = nums[0];
        string cur = to_string(nums[0]);
        for (int i = 1; i < len; i++) {
            if (nums[i] == prev + 1) {
                prev = nums[i];
            }
            else {
                string after = to_string(prev);
                string r = cur;
                if (after != cur) {
                    r += "->" + after;
                }
                res.push_back(r);
                prev = nums[i];
                cur = to_string(prev);
            }
        }
        string after = to_string(prev);
        string r = cur;
        if (after != cur) {
            r += "->" + after;
        }
        res.push_back(r);
        return res;
    }
};
