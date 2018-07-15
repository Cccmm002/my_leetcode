// Given an integer array nums, find the contiguous subarray (containing at least one number) which has the largest sum and return its sum.
//
// Example:
//
//
// Input: [-2,1,-3,4,-1,2,1,-5,4],
// Output: 6
// Explanation: [4,-1,2,1] has the largest sum = 6.
//
//
// Follow up:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
//


int maxSubArray(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    int *s=(int*)malloc(sizeof(int)*numsSize);
    s[0]=nums[0];
    int max=s[0];
    for(int i=1;i<numsSize;i++) {
        int ns=nums[i]+s[i-1];
        s[i]=ns>nums[i]?ns:nums[i];
        max=max<s[i]?s[i]:max;
    }
    free(s);
    return max;
}
