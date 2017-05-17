// Given a non-empty array containing only positive integers, find if the array can be partitioned into two subsets such that the sum of elements in both subsets is equal.
//
//
// Note:
//
// Each of the array element will not exceed 100.
// The array size will not exceed 200.
//
//
//
// Example 1:
//
// Input: [1, 5, 11, 5]
//
// Output: true
//
// Explanation: The array can be partitioned as [1, 5, 5] and [11].
//
//
//
// Example 2:
//
// Input: [1, 2, 3, 5]
//
// Output: false
//
// Explanation: The array cannot be partitioned into equal sum subsets.


bool canPartition(int* nums, int numsSize) {
    int sum = 0;
    for(int i=0; i<numsSize; i++)
        sum += nums[i];
    if(sum % 2 != 0) return false;
    bool **f = (bool**)malloc(sizeof(bool*)*numsSize);
    for(int i=0; i<numsSize; i++)
        f[i] = (bool*)malloc(sizeof(bool)*(sum/2+1));
    for(int i=0;i<=sum/2;i++)
        f[0][i] = i == nums[0];
    for(int i = 1;i<numsSize;i++) {
        for(int j=0;j<=sum/2;j++) {
            if(j-nums[i]<0)
                f[i][j] = f[i-1][j];
            else
                f[i][j] = f[i-1][j-nums[i]] || f[i-1][j];
        }
    }
    return f[numsSize-1][sum/2];
}
