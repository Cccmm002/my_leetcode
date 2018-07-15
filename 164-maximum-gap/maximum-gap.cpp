// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Return 0 if the array contains less than 2 elements.
//
// Example 1:
//
//
// Input: [3,6,9,1]
// Output: 3
// Explanation: The sorted form of the array is [1,3,6,9], either
//              (3,6) or (6,9) has the maximum difference 3.
//
// Example 2:
//
//
// Input: [10]
// Output: 0
// Explanation: The array contains less than 2 elements, therefore return 0.
//
// Note:
//
//
// 	You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
// 	Try to solve it in linear time/space.
//
//


class Solution {
public:
    int maximumGap(vector<int>& nums) {
        int len = nums.size();
        if (len < 2) return 0;
        int largest = 0;
        int smallest = INT_MAX;
        for (int i = 0; i < len; i++) {
            if (nums[i] > largest)
                largest = nums[i];
            if (nums[i] < smallest)
                smallest = nums[i];
        }
        if (largest == smallest) return 0;
        int gap = (int)(((double)(largest - smallest))/(len - 1)) + 1;
        int bucketCount = (largest - smallest)/gap + 1;
        vector<int> bucketMin(bucketCount, INT_MAX);
        vector<int> bucketMax(bucketCount, 0);
        vector<bool> bucketHas(bucketCount, false);
        for (int i = 0; i < len; i++) {
            int k = (nums[i] - smallest)/gap;
            bucketHas[k] = true;
            bucketMax[k] = nums[i] > bucketMax[k] ? nums[i] : bucketMax[k];
            bucketMin[k] = nums[i] < bucketMin[k] ? nums[i] : bucketMin[k];
        }
        int maxGap = bucketMax[0] - bucketMin[0];
        int prevMax = bucketMax[0];
        for (int i = 0; i < bucketCount; i++) {
            if (!bucketHas[i]) continue;
            int cur = bucketMin[i] - prevMax;
            maxGap = maxGap > cur ? maxGap : cur;
            prevMax = bucketMax[i];
        }
        return maxGap;
    }
};
