// Given an array of integers, return indices of the two numbers such that they add up to a specific target.
//
// You may assume that each input would have exactly one solution, and you may not use the same element twice.
//
//
// Example:
//
// Given nums = [2, 7, 11, 15], target = 9,
//
// Because nums[0] + nums[1] = 2 + 7 = 9,
// return [0, 1].


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target) {
    int *res=(int*)malloc(sizeof(int)*2);
    for (res[0]=0;res[0]<numsSize;res[0]++) {
        int another=target-nums[res[0]];
        for (res[1] = 0; res[1] < numsSize; res[1]++) {
            if(res[0]==res[1]) continue;
            if(another==nums[res[1]])
                return res;
        }
    }
    return 0;
}
