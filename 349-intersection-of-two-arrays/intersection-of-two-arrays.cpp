// Given two arrays, write a function to compute their intersection.
//
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2].
//
//
// Note:
//
// Each element in the result must be unique.
// The result can be in any order.


class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        set<int> s1,s2;
        for(int i:nums1)
            s1.insert(i);
        for(int i:nums2)
            s2.insert(i);
        set<int> *smin,*smax;
        if(s1.size()<s2.size()){
            smin=&s1;
            smax=&s2;
        } else {
            smax=&s1;
            smin=&s2;
        }
        set<int>::iterator it=smin->begin();
        while(it!=smin->end()){
            if(smax->find(*it)!=smax->end())
                res.push_back(*it);
            it++;
        }
        return res;
    }
};
