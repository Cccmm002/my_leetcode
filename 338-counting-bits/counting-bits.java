// Given a non negative integer number num. For every numbers i in the range 0 ≤ i ≤ num calculate the number of 1's in their binary representation and return them as an array.
//
//
// Example:
// For num = 5 you should return [0,1,1,2,1,2].
//
//
// Follow up:
//
// It is very easy to come up with a solution with run time O(n*sizeof(integer)). But can you do it in linear time O(n) /possibly in a single pass?
// Space complexity should be O(n).
// Can you do it like a boss? Do it without using any builtin function like __builtin_popcount  in c++ or in any other language.
//
//
//
// Credits:Special thanks to @ syedee  for adding this problem and creating all test cases.


public class Solution {
    public int[] countBits(int num) {
        int[] res=new int[num+1];
        res[0]=0;
        if(num==0) return res;
        res[1]=1;
        int two=2;
        int twoTwo=4;
        for(int i=2;i<=num;i++) {
            if(i==twoTwo) {
                two=twoTwo;
                twoTwo*=2;
            }
            res[i]=res[i-two]+1;
        }
        return res;
    }
}
