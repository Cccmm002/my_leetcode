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
    public int threeSumSmaller(int[] nums, int target) {
        int n = nums.length;
        Arrays.sort(nums);
        int count = 0;
        for (int k = 2; k < n; k++) {
            int left = 0, right = k - 1;
            int t = target - nums[k];
            while (left < right) {
                if (nums[left] + nums[right] < t) {
                    count += right - left;
                    left++;
                }
                else{
                    right--;
                }
            }
        }
        return count;
    }
}
