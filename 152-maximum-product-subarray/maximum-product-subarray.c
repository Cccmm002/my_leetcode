// Given an integer array nums, find the contiguous subarray within an array (containing at least one number) which has the largest product.
//
// Example 1:
//
//
// Input: [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.
//
//
// Example 2:
//
//
// Input: [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.
//


int maxProduct(int* nums, int numsSize) {
    if(numsSize==0) return ;
    int *p=(int*)malloc(sizeof(int)*numsSize);
    int *n=(int*)malloc(sizeof(int)*numsSize);
    p[0]=(nums[0]>0)?nums[0]:0;
    n[0]=(nums[0]<0)?nums[0]:0;
    int max_p=p[0];
    int min_n=n[0];
    bool zero=false;
    for(int i=1;i<numsSize;i++) {
        if(nums[i]>0) {
            int np=p[i-1]==0?nums[i]:nums[i]*p[i-1];
            int nn=n[i-1]==0?0:n[i-1]*nums[i];
            p[i]=np>nums[i]?np:nums[i];
            n[i]=nn;
        }
        else if(nums[i]==0) {
            zero=true;
            p[i]=0;
            n[i]=0;
        }
        else {
            int np=n[i-1]==0?0:nums[i]*n[i-1];
            int nn=p[i-1]==0?0:nums[i]*p[i-1];
            p[i]=np;
            n[i]=nn<nums[i]?nn:nums[i];
        }
        max_p=max_p>p[i]?max_p:p[i];
        min_n=min_n<n[i]?min_n:n[i];
    }
    return max_p==0?(zero?0:min_n):max_p;
}
