// The gray code is a binary numeral system where two successive values differ in only one bit.
//
// Given a non-negative integer n representing the total number of bits in the code, print the sequence of gray code. A gray code sequence must begin with 0.
//
// For example, given n = 2, return [0,1,3,2]. Its gray code sequence is:
//
// 00 - 0
// 01 - 1
// 11 - 3
// 10 - 2
//
//
// Note:
// For a given n, a gray code sequence is not uniquely defined.
//
// For example, [0,2,3,1] is also a valid gray code sequence according to the above definition.
//
// For now, the judge is able to judge based on one instance of gray code sequence. Sorry about that.


class Solution {
public:
    vector<int> grayCode(int n) {
        vector<int> res;
        if(n==0){
            res.push_back(0);
            return res;
        }
        if(n==1){
            res.push_back(0);
            res.push_back(1);
            return res;
        }
        vector<int> last=grayCode(n-1);
        int len=last.size();
        for(int i=0;i<len;i++)
            res.push_back(last[i]);
        int prefix=1<<(n-1);
        for(int i=len-1;i>=0;i--)
            res.push_back(last[i]+prefix);
        return res;
    }
};