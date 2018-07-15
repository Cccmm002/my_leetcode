// Given n, how many structurally unique BST's (binary search trees) that store values 1 ... n?
//
// Example:
//
//
// Input: 3
// Output: 5
// Explanation:
// Given n = 3, there are a total of 5 unique BST's:
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3
//
//


class Solution {
public:
    int numTrees(int n) {
        if(n==0) return 1;
        int *f=(int*)malloc(sizeof(int)*(n+1));
        f[1]=1;
        f[2]=2;
        for(int i=3;i<=n;i++){
            f[i]=2*f[i-1];
            for(int t=2;t<=i-1;t++)
                f[i]+=f[t-1]*f[i-t];
        }
        int res=f[n];
        free(f);
        return res;
    }
};
