//
// You are standing at position 0 on an infinite number line.  There is a goal at position target.
//
// On each move, you can either go left or right.  During the n-th move (starting from 1), you take n steps.
//
// Return the minimum number of steps required to reach the destination.
//
//
// Example 1:
//
// Input: target = 3
// Output: 2
// Explanation:
// On the first move we step from 0 to 1.
// On the second step we step from 1 to 3.
//
//
//
// Example 2:
//
// Input: target = 2
// Output: 3
// Explanation:
// On the first move we step from 0 to 1.
// On the second move we step  from 1 to -1.
// On the third move we step from -1 to 2.
//
//
//
// Note:
// target will be a non-zero integer in the range [-10^9, 10^9].
//


int reachNumber(int n) {
    if(n < 0){n = -n;}
    long sum=0, ans=0,p=1;
    for (p = 1; sum < n; sum += p, p++, ans++);
    long diff = sum - n; 
    if(n == 0) return 0;
    else if(diff % 2 == 0) return ans;
    else if((diff + p) % 2 == 0) return ans + 1;
    else return ans + 2;
}
