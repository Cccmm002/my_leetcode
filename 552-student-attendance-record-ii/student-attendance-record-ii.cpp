// Given a positive integer n, return the number of all possible attendance records with length n, which will be regarded as rewardable. The answer may be very large, return it after mod 109 + 7.
//
// A student attendance record is a string that only contains the following three characters:
//
//
//
// 'A' : Absent. 
// 'L' : Late.
//  'P' : Present. 
//
//
//
//
// A record is regarded as rewardable if it doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).
//
// Example 1:
//
// Input: n = 2
// Output: 8 
// Explanation:
// There are 8 records with length 2 will be regarded as rewardable:
// "PP" , "AP", "PA", "LP", "PL", "AL", "LA", "LL"
// Only "AA" won't be regarded as rewardable owing to more than one absent times. 
//
//
//
// Note:
// The value of n won't exceed 100,000.
//
//
//
//


class Solution {
public:
    int checkRecord(int n) {
        if (n == 1) return 3;
        int m = 1000000007;
        int *a = new int[n + 1];
        int *p = new int[n + 1];
        int *l = new int[n + 1];
        a[1] = 1;
        p[1] = 1;
        l[1] = 1;
        for (int i = 2; i <= n; i++) {
            p[i] = ((a[i-1] + p[i-1])%m + l[i-1])%m;
            if (i == 2) l[i] = 3;
            else l[i] = ((p[i-1]+a[i-1])%m+(p[i-2]+a[i-2])%m)%m;
            if (i == 2) a[i] = 2;
            else if (i == 3) a[i] = 4;
            else a[i] = ((a[i-1]+a[i-2])%m+a[i-3])%m;
        }
        int res = ((a[n]+p[n])%m+l[n]%m)%m;
        delete[] a;
        delete[] p;
        delete[] l;
        return res;
    }
};
