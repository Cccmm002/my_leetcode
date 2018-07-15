// We are playing the Guess Game. The game is as follows: 
//
// I pick a number from 1 to n. You have to guess which number I picked.
//
// Every time you guess wrong, I'll tell you whether the number is higher or lower.
//
// You call a pre-defined API guess(int num) which returns 3 possible results (-1, 1, or 0):
//
// -1 : My number is lower
//  1 : My number is higher
//  0 : Congrats! You got it!
//
//
// Example:
//
// n = 10, I pick 6.
//
// Return 6.
//
//


// Forward declaration of guess API.
// @param num, your guess
// @return -1 if my number is lower, 1 if my number is higher, otherwise return 0
int guess(int num);

class Solution {
public:
    int guessNumber(int n) {
        unsigned long long begin=1;
        unsigned long long end=(unsigned long long)n+1;
        while(begin<end) {
            unsigned long long middle=(begin+end)/2;
            int ret=guess((int)middle);
            //cout<<middle<<" "<<ret<<endl;
            if(ret==0)
                return middle;
            else if(ret==1)
                begin=middle+1;
            else
                end=middle;
        }
        return end;
    }
};
