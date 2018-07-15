// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed. All houses at this place are arranged in a circle. That means the first house is the neighbor of the last one. Meanwhile, adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [2,3,2]
// Output: 3
// Explanation: You cannot rob house 1 (money = 2) and then rob house 3 (money = 2),
//              because they are adjacent houses.
//
//
// Example 2:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//


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
