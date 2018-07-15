// Given a non-empty array of digits representing a non-negative integer, plus one to the integer.
//
// The digits are stored such that the most significant digit is at the head of the list, and each element in the array contain a single digit.
//
// You may assume the integer does not contain any leading zero, except the number 0 itself.
//
// Example 1:
//
//
// Input: [1,2,3]
// Output: [1,2,4]
// Explanation: The array represents the integer 123.
//
//
// Example 2:
//
//
// Input: [4,3,2,1]
// Output: [4,3,2,2]
// Explanation: The array represents the integer 4321.
//
//


/**
 * Return an array of size *returnSize.
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* plusOne(int* digits, int digitsSize, int* returnSize) {
    int *rev = (int*)malloc(sizeof(int)*(digitsSize+1));
    int flag=1;
    for(int i=0;i<digitsSize;i++) {
        int cur=digits[digitsSize-i-1]+flag;
        if(cur>=10) {
            flag=1;
            cur=cur-10;
        }
        else {
            flag=0;
        }
        rev[i]=cur;
    }
    int l=(flag>0)?(digitsSize+1):(digitsSize);
    int *res = (int*)malloc(sizeof(int)*l);
    if(flag>0) res[0]=1;
    int p=l-1;
    for(int i=0;i<digitsSize;i++) {
        res[p]=rev[i];
        p--;
    }
    free(rev);
    *returnSize=l;
    return res;
}
