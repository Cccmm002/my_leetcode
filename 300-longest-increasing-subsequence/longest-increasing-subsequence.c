// Given an unsorted array of integers, find the length of longest increasing subsequence.
//
//
// For example,
// Given [10, 9, 2, 5, 3, 7, 101, 18],
// The longest increasing subsequence is [2, 3, 7, 101], therefore the length is 4. Note that there may be more than one LIS combination, it is only necessary for you to return the length.
//
//
// Your algorithm should run in O(n2) complexity.
//
//
// Follow up: Could you improve it to O(n log n) time complexity? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


int lengthOfLIS(int* nums, int numsSize) {
    if(numsSize==1) return 1;
    int *dp=(int*)malloc(sizeof(int)*numsSize);
    dp[0]=1;
    int res=0;
    for(int i=1;i<numsSize;i++) {
        int max=0;
        for(int j=0;j<i;j++) {
            if(nums[j]>=nums[i]) continue;
            max=max>dp[j]?max:dp[j];
        }
        dp[i]=max+1;
        res=res>dp[i]?res:dp[i];
    }
    free(dp);
    return res;
}
