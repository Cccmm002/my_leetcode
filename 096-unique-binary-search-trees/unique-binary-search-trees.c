// Given n, how many structurally unique BST's (binary search trees) that store values 1...n?
//
//
// For example,
// Given n = 3, there are a total of 5 unique BST's.
//
//
//    1         3     3      2      1
//     \       /     /      / \      \
//      3     2     1      1   3      2
//     /     /       \                 \
//    2     1         2                 3


int numTrees(int n) {
    if(n==1) return 1;
    int *f = (int*)malloc(sizeof(int)*(n + 1));
    f[0] = 1;
    f[1] = 1;
    for(int i=2;i<=n;i++) {
        f[i] = 0;
        for(int k=1;k<=i;k++) {
            f[i] += f[k - 1]*f[i - k];
        }
    }
    int res = f[n];
    free(f);
    return res;
}
