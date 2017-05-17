// Implement int sqrt(int x).
//
// Compute and return the square root of x.


class Solution {
public:
    int mySqrt(int x) {
        if(x==0) return 0;
        if(x==1) return 1;
        long long i=x/2;
        while(i*i>x) i=(i+x/i)/2;
        return i;
    }
};
