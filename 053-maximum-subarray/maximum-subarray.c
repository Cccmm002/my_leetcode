// Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//
// For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
// the contiguous subarray [4,-1,2,1] has the largest sum = 6.
//
//
// click to show more practice.
//
// More practice:
//
// If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.


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
