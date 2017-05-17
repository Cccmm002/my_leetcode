// Given a non negative integer number num. For every numbers i in the range 0 &le; i &le; num calculate the number of 1's in their binary representation and return them as an array.
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


class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> res;
        res.push_back(0);
        if(num==0) return res;
        res.push_back(1);
        int curTwo=2;
        for(int i=2;i<=num;i++) {
            if(i==curTwo*2)
                curTwo*=2;
            res.push_back(res[i-curTwo]+1);
        }
        return res;
    }
};
