//  Given an integer array with all positive numbers and no duplicates, find the number of possible combinations that add up to a positive integer target.
//
// Example:
//
// nums = [1, 2, 3]
// target = 4
//
// The possible combination ways are:
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
//
// Note that different sequences are counted as different combinations.
//
// Therefore the output is 7.
//
//
//
// Follow up:
// What if negative numbers are allowed in the given array?
// How does it change the problem?
// What limitation we need to add to the question to allow negative numbers? 
//
// Credits:Special thanks to @pbrother for adding this problem and creating all test cases.


int combinationSum4(int* nums, int numsSize, int target) {
    int *memory=(int*)malloc(sizeof(int)*(target+1));
    memset(memory,0,sizeof(int)*(target+1));
    for(int i=1;i<=target;i++)
    {
        for(int j=0;j<numsSize;j++)
        {
            int cur=i-nums[j];
            if(cur<0)
                continue;
            if(cur==0)
                memory[i]++;
            else
                memory[i]+=memory[cur];
        }
    }
    int res=memory[target];
    free(memory);
    return res;
}
