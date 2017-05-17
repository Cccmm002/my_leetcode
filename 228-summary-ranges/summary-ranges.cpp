// Given a sorted integer array without duplicates, return the summary of its ranges.
//
//
// For example, given [0,1,2,4,5,7], return ["0->2","4->5","7"].
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
