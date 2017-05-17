// Given an unsorted array, find the maximum difference between the successive elements in its sorted form.
//
// Try to solve it in linear time/space.
//
// Return 0 if the array contains less than 2 elements.
//
// You may assume all elements in the array are non-negative integers and fit in the 32-bit signed integer range.
//
// Credits:Special thanks to @porker2008 for adding this problem and creating all test cases.


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
