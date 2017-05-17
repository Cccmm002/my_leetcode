// Given an unsorted integer array, find the first missing positive integer.
//
//
//
// For example,
// Given [1,2,0] return 3,
// and [3,4,-1,1] return 2.
//
//
//
// Your algorithm should run in O(n) time and uses constant space.


int firstMissingPositive(int* nums, int numsSize) {
    for (int i = 0; i < numsSize; i++) {
        while (!(nums[i] <= 0 || nums[i] > numsSize) && nums[nums[i] - 1] != nums[i]) {
            int temp = nums[nums[i] - 1];
            nums[nums[i] - 1] = nums[i];
            nums[i] = temp;
        }
    }
    // for (int i=0;i<numsSize;i++) printf("%d ", nums[i]);
    for (int i = 0; i < numsSize; i++) {
        if (i != nums[i] - 1)
            return i + 1;
    }
    return numsSize + 1;
}