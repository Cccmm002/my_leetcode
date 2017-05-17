// Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
// You may assume the integer do not contain any leading zero, except the number 0 itself.
//
// The digits are stored such that the most significant digit is at the head of the list.


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
