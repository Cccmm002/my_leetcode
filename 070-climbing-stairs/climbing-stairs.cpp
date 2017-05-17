// You are climbing a stair case. It takes n steps to reach to the top.
//
// Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?
//
//
// Note: Given n will be a positive integer.


class Solution {
public:
    int climbStairs(int n) {
        int *r=(int*)malloc(sizeof(int)*(n+1));
        r[0]=1;
        r[1]=1;
        for(int i=2;i<=n;i++)
            r[i]=r[i-1]+r[i-2];
        int res=r[n];
        free(r);
        return res;
    }
};
