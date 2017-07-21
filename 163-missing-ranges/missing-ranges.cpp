// Given a sorted integer array where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
//
// For example, given [0, 1, 3, 50, 75], lower = 0 and upper = 99, return ["2", "4->49", "51->74", "76->99"].


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        long long should = lower;
        for (int c : nums) {
            long long cur = (long long)c;
            if (cur < should) continue;
            if (cur != should) {
                long long right = cur - 1;
                if (right == should) {
                    res.push_back(to_string(should));
                }
                else {
                    res.push_back(to_string(should) + "->" + to_string(right));
                }
            }
            should = cur + 1;
        }
        if (should == upper)
            res.push_back(to_string(should));
        else if(should < upper)
            res.push_back(to_string(should) + "->" + to_string(upper));
        return res;
    }
};
