// There is a fence with n posts, each post can be painted with one of the k colors.
// You have to paint all the posts such that no more than two adjacent fence posts have the same color. 
// Return the total number of ways you can paint the fence. 
//
// Note:
// n and k are non-negative integers.


int numWays(int n, int k) {
    if (n == 0 || k == 0) return 0;
    int t = 0;
    int f = k;
    for (int i = 1; i < n; i++) {
        int nt = f;
        int nf = (k - 1) * (t + f);
        t = nt;
        f = nf;
    }
    return (t + f);
}
