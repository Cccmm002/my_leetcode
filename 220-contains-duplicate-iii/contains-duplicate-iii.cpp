// Given an array of integers, find out whether there are two distinct indices i and j in the array such that the absolute difference between nums[i] and nums[j] is at most t and the absolute difference between i and j is at most k.


class Solution {
public:
bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    if(k<=0) return false;
    int length=nums.size();
    k=(k>=length)?(length-1):k;
    multiset<int> s;
    for(int i=1;i<=k;i++)
        s.insert(nums[i]);
    for(int i=0;i<length-1;i++){
        std::multiset<int>::iterator lower=s.lower_bound(nums[i]-t);
        if(lower!=s.end()){
            int lower_num=*lower;
            if(lower_num<=nums[i]+t)
                return true;
        }
        s.erase(nums[i+1]);
        if(i+k+1<length)
            s.insert(nums[i + k + 1]);
    }
    return false;
}
};
