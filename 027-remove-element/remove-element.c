// Given an array and a value, remove all instances of that value in place and return the new length.
//
//
// Do not allocate extra space for another array, you must do this in place with constant memory.
//
// The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//
// Example:
// Given input array nums = [3,2,2,3], val = 3
//
//
// Your function should return length = 2, with the first two elements of nums being 2.


int removeElement(int* nums, int numsSize, int val) {
    if(numsSize<=0) return 0;
    int b=0;
    int e=numsSize-1;
    while(b<e) {
        while(b<e && nums[b]!=val) b++;
        while(b<e && nums[e]==val) e--;
        if(b>=e) break;
        nums[b]=nums[e];
        b++; e--;
    }
    return nums[e]==val?(e):(e+1);
}
