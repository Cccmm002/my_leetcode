// Description:
// Count the number of prime numbers less than a non-negative number, n.
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


int countPrimes(int n) {
    if (n <= 2) return 0;
    int *p = (int*)malloc(sizeof(int)*n);
    for (int i = 0; i < n; i++) p[i] = 1;
    int res = 0;
    for (int i = 2; i < n; i++) {
        if (p[i] == 1) res++;
        int j = 2;
        while (i*j < n) {
            p[i*j] = 0;
            j++;
        }
    }
    free(p);
    return res;
}
