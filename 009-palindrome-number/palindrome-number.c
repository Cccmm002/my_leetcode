// Determine whether an integer is a palindrome. Do this without extra space.
//
// click to show spoilers.
//
// Some hints:
//
// Could negative integers be palindromes? (ie, -1)
//
// If you are thinking of converting the integer to string, note the restriction of using extra space.
//
// You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//
// There is a more generic way of solving this problem.


int digits(int x){
    int res=0;
    while(x>0){
        x/=10;
        res++;
    }
    return res;
}

bool isPalindrome(int x) {
    if(x<0) 
        return false;
    int d=digits((long)x);
    while(d>1){
        int test=x%10;
        if(test==0 && digits(x)==d)
            return false;
        for(int i=0;i<d-1;i++)
            test=test*10;
        int r=x-test;
        if (r<0)
            return false;
        else{
            d-=2;
            r=r/10;
            x=r;
        }
    }
    return true;
}
