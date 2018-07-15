// Given an array of n integers nums and a target, find the number of index triplets i, j, k with 0 <= i < j < k < n that satisfy the condition nums[i] + nums[j] + nums[k] < target.
//
// Example:
//
//
// Input: nums = [-2,0,1,3], and target = 2
// Output: 2 
// Explanation: Because there are two triplets which sums are less than 2:
//              [-2,0,1]
//              [-2,0,3]
//
//
// Follow up: Could you solve it in O(n2) runtime?
//


class Solution {
public:
    int threeSumSmaller(vector<int>& nums, int target) {
        int n = nums.size();
        if (n < 3) return 0;
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int a = 0; a < n - 2; a++) {
            int b = a + 1, c = n - 1;
            while (b < c) {
                if (nums[a] + nums[b] + nums[c] >= target) {
                    c--;
                }
                else {
                    res += c - b;
                    b++;
                }
            }
        }
        return res;
    }
};
