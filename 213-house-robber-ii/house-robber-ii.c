// Note: This is an extension of House Robber.
//
// After robbing those houses on that street, the thief has found himself a new place for his thievery so that he will not get too much attention. This time, all houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, the security system for these houses remain the same as for those in the previous street. 
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Credits:Special thanks to @Freezen for adding this problem and creating all test cases.


int rob(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    if(numsSize==1) return nums[0];
    int *a=(int*)malloc(sizeof(int)*numsSize);
    int *b=(int*)malloc(sizeof(int)*numsSize);
    a[0]=0; b[0]=nums[0];
    a[1]=nums[1]; b[1]=b[0];
    for(int i=2;i<numsSize;i++) {
        a[i]=nums[i]+a[i-2]>a[i-1]?(nums[i]+a[i-2]):a[i-1];
        b[i]=nums[i]+b[i-2]>b[i-1]?(nums[i]+b[i-2]):b[i-1];
    }
    b[numsSize-1]=b[numsSize-2];
    return a[numsSize-1]>b[numsSize-1]?a[numsSize-1]:b[numsSize-1];
}
