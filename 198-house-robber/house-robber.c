// You are a professional robber planning to rob houses along a street. Each house has a certain amount of money stashed, the only constraint stopping you from robbing each of them is that adjacent houses have security system connected and it will automatically contact the police if two adjacent houses were broken into on the same night.
//
// Given a list of non-negative integers representing the amount of money of each house, determine the maximum amount of money you can rob tonight without alerting the police.
//
// Credits:Special thanks to @ifanchu for adding this problem and creating all test cases. Also thanks to @ts for adding additional test cases.


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
