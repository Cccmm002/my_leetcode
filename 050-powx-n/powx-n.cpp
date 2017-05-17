// Implement pow(x, n).


class Solution {
public:
    double myPow(double x, int n) {
        if(x==0) return 0.0;
        if(x==1) return 1.0;
        if(n==0) return 1.0;
        if(n==1) return x;
        if(n<0){
            if(n==-2147483648)
                return (1.0/x)*myPow(1.0/x,2147483647);
            else
                return myPow(1.0/x,-n);
        }
        if(n%2==0)
            return myPow(x*x,n/2);
        else
            return x*myPow(x*x,n/2);
    }
};
