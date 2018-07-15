// Given an array consists of non-negative integers,  your task is to count the number of triplets chosen from the array that can make triangles if we take them as side lengths of a triangle.
//
// Example 1:
//
// Input: [2,2,3,4]
// Output: 3
// Explanation:
// Valid combinations are: 
// 2,3,4 (using the first 2)
// 2,3,4 (using the second 2)
// 2,2,3
//
//
//
// Note:
//
// The length of the given array won't exceed 1000.
// The integers in the given array are in the range of [0, 1000].
//
//
//


class Solution {
    public int triangleNumber(int[] nums) {
        int n = nums.length;
        Arrays.sort(nums);
        int count = 0;
        for (int i = 2; i < n; i++) {
            int left = 0, right = i - 1;
            int target = nums[i];
            while (left < right) {
                if (nums[left] + nums[right] > target) {
                    count += right - left;
                    right--;
                }
                else {
                    left++;
                }
            }
        }
        return count;
    }
}
