// Given two arrays, write a function to compute their intersection.
//
//
// Example:
// Given nums1 = [1, 2, 2, 1], nums2 = [2, 2], return [2, 2].
//
//
// Note:
//
// Each element in the result should appear as many times as it shows in both arrays.
// The result can be in any order.
//
//
//
// Follow up:
//
// What if the given array is already sorted? How would you optimize your algorithm?
// What if nums1's size is small compared to nums2's size? Which algorithm is better?
// What if elements of nums2 are stored on disk, and the memory is limited such that you cannot load all elements into the memory at once?


class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        multiset<int> s1,s2;
        for(int i:nums1)
            s1.insert(i);
        for(int i:nums2)
            s2.insert(i);
        multiset<int> *smin,*smax;
        if(s1.size()<s2.size()){
            smin=&s1;
            smax=&s2;
        } else {
            smax=&s1;
            smin=&s2;
        }
        multiset<int>::iterator it=smin->begin();
        while(it!=smin->end()){
            multiset<int>::iterator cur=smax->find(*it);
            if(cur!=smax->end()){
                res.push_back(*it);
                smax->erase(cur);
            }
            it++;
        }
        return res;
    }
};
