// A sequence of numbers is called a wiggle sequence if the differences between successive numbers strictly alternate between positive and negative. The first difference (if one exists) may be either positive or negative. A sequence with fewer than two elements is trivially a wiggle sequence. 
//
// For example, [1,7,4,9,2,5] is a wiggle sequence because the differences (6,-3,5,-7,3) are alternately positive and negative. In contrast, [1,4,7,2,5] and [1,7,4,5,5] are not wiggle sequences, the first because its first two differences are positive and the second because its last difference is zero.
//
// Given a sequence of integers, return the length of the longest subsequence that is a wiggle sequence. A subsequence is obtained by deleting some number of elements (eventually, also zero) from the original sequence, leaving the remaining elements in their original order.
//
// Examples:
//
// Input: [1,7,4,9,2,5]
// Output: 6
// The entire sequence is a wiggle sequence.
//
// Input: [1,17,5,10,13,15,10,5,16,8]
// Output: 7
// There are several subsequences that achieve this length. One is [1,17,10,13,10,16,8].
//
// Input: [1,2,3,4,5,6,7,8,9]
// Output: 2
//
//
//
// Follow up:
// Can you do it in O(n) time?
//
//
// Credits:Special thanks to @agave and @StefanPochmann for adding this problem and creating all test cases.


int helper(int* nums, int numsSize, bool first) {
    int *d=(int*)malloc(sizeof(int)*numsSize);
    bool *b=(bool*)malloc(sizeof(bool)*numsSize);
    d[0]=1;
    b[0]=first;
    int res=1;
    for(int i=1;i<numsSize;i++) {
        d[i]=1;
        for(int j=0;j<i;j++) {
            if(b[j] && nums[i]>=nums[j]) continue;
            if(!b[j] && nums[i]<=nums[j]) continue;
            int cur=d[j]+1;
            if(cur>d[i]) {
                b[i]=!b[j];
                d[i]=cur;
            }
        }
        res=(res>d[i])?res:d[i];
    }
    free(d); free(b);
    return res;
}

int wiggleMaxLength(int* nums, int numsSize) {
    if(numsSize==0) return 0;
    int a=helper(nums,numsSize,true);
    int b=helper(nums,numsSize,false);
    return (a>b)?a:b;
}
