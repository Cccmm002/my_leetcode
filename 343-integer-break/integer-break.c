//
// Given a positive integer n, break it into the sum of at least two positive integers and maximize the product of those integers. Return the maximum product you can get.
//
//
//
// For example, given n = 2, return 1 (2 = 1 + 1); given n = 10, return 36 (10 = 3 + 3 + 4).
//
//
//
// Note: You may assume that n is not less than 2 and not larger than 58.
//
//
// Credits:Special thanks to @jianchao.li.fighter for adding this problem and creating all test cases.


int integerBreak(int n) {
    if(n==2) return 1;
    if(n==3) return 2;
    int* arr=(int*)malloc(sizeof(int)*(n+1));
    arr[2]=2;
    arr[3]=3;
    arr[4]=4;
    arr[5]=6;
    for(int i=6;i<=n;i++) {
        int three=3*arr[i-3];
        int four=4*arr[i-4];
        arr[i]=three>four?three:four;
    }
    return arr[n];
}
