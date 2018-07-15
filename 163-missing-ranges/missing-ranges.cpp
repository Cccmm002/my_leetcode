// Given a sorted integer array nums, where the range of elements are in the inclusive range [lower, upper], return its missing ranges.
//
// Example:
//
//
// Input: nums = [0, 1, 3, 50, 75], lower = 0 and upper = 99,
// Output: ["2", "4->49", "51->74", "76->99"]
//
//


class Solution {
public:
    vector<string> findMissingRanges(vector<int>& nums, int lower, int upper) {
        vector<string> res;
        int n = nums.size();
        vector<long long> v(n + 1, 0);
        for (int i = 0; i < n; i++) v[i] = nums[i];
        long long prev = ((long long)lower) - 1;
        v[n] = ((long long)upper) + 1;
        for (int i = 0; i <= n; i++) {
            long long diff = v[i] - prev;
            if (diff == 2) 
                res.push_back(to_string(v[i] - 1));
            else if (diff > 2) {
                string left = to_string(prev + 1);
                string right = to_string(v[i] - 1);
                res.push_back(left + "->" + right);
            }
            prev = v[i];
        }
        return res;
    }
};
