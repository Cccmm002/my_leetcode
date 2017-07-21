// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
// For example, given nums = [-2, 0, 1, 3], and target = 2.
//
// Return 2. Because there are two triplets which sums are less than 2:
//
// [-2, 0, 1]
// [-2, 0, 3]
//
//
// Follow up:
// Could you solve it in O(n2) runtime?


class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int len = nums.size();
        int res = 0;
        for (int i = 0; i < len; i++) {
            //if (i != 0 && nums[i] == nums[i - 1]) continue;
            int beg = i + 1;
            int end = len - 1;
            while (beg < end) {
                if (nums[i] < target - (nums[beg] + nums[end])) {
                    res += end - beg;
                    beg++;
                }
                else {
                    end--;
                }
            }
        }
        return res;
    }
};
