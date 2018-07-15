// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Example 1:
//
//
// Input: [1,2,3,1]
// Output: 4
// Explanation: Rob house 1 (money = 1) and then rob house 3 (money = 3).
//              Total amount you can rob = 1 + 3 = 4.
//
// Example 2:
//
//
// Input: [2,7,9,3,1]
// Output: 12
// Explanation: Rob house 1 (money = 2), rob house 3 (money = 9) and rob house 5 (money = 1).
//              Total amount you can rob = 2 + 9 + 1 = 12.
//
//


int solve(int *nums, int numsSize, int current, int* memory) {
    if(current==0)
        return nums[0];
    if(current==1)
        return nums[1]>nums[0]?nums[1]:nums[0];
    if(memory[current]>=0) 
        return memory[current];
    int r=nums[current]+solve(nums,numsSize,current-2,memory);
    int n=solve(nums,numsSize,current-1,memory);
    int res=r>n?r:n;
    memory[current]=res;
    return res;
}

int rob(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    int *memory=(int*)malloc(sizeof(int)*numsSize);
    for(int i=0;i<numsSize;i++) memory[i]=-1;
    int res=solve(nums,numsSize,numsSize-1,memory);
    free(memory);
    return res;
}
