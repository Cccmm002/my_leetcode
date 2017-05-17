// Given an index k, return the kth row of the Pascal's triangle.
//
//
// For example, given k = 3,
// Return [1,3,3,1].
//
//
//
// Note:
// Could you optimize your algorithm to use only O(k) extra space?


class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res={1};
        if(rowIndex==0) return res;
        res.push_back(1);
        if(rowIndex==1) return res;
        int curRow=1;
        while(curRow<rowIndex) {
            auto it=res.begin()+1;
            int lastNum=1;
            while(it!=res.end()){
                int n=lastNum+*it;
                lastNum=*it;
                *it=n;
                it++;
            }
            res.push_back(1);
            curRow++;
        }
        return res;
    }
};
