// Determine whether an integer is a palindrome. An integer is a palindrome when it reads the same backward as forward.
//
// Example 1:
//
//
// Input: 121
// Output: true
//
//
// Example 2:
//
//
// Input: -121
// Output: false
// Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.
//
//
// Example 3:
//
//
// Input: 10
// Output: false
// Explanation: Reads 01 from right to left. Therefore it is not a palindrome.
//
//
// Follow up:
//
// Coud you solve it without converting the integer to a string?
//


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
