// Given an array nums, write a function to move all 0's to the end of it while maintaining the relative order of the non-zero elements.
//
// Example:
//
//
// Input: [0,1,0,3,12]
// Output: [1,3,12,0,0]
//
// Note:
//
//
// 	You must do this in-place without making a copy of the array.
// 	Minimize the total number of operations.
//
//


void moveZeroes(int* nums, int numsSize) {
    int p = 0;
    while(p<numsSize && nums[p]!=0) p++;
    int f = p+1;
    while(p<numsSize) {
        while(f<numsSize && nums[f]==0) f++;
        if(f>=numsSize) break;
        nums[p]=nums[f];
        p++; f++;
    }
    while(p<numsSize) nums[p++]=0;
}
