// Given an array of integers and an integer k, find out whether there are two distinct indices i and j in the array such that nums[i] = nums[j] and the absolute difference between i and j is at most k.


class Solution {
public:
bool containsNearbyDuplicate(vector<int>& nums, int k) {
    if(k==0) return false;
    int length=nums.size();
    std::unordered_map<int,int> m;
    k=(k>length)?(length-1):k;
    for(int i=1;i<=k;i++)
        m[nums[i]]++;
    for(int i=0;i<length;i++){
        if((m.count(nums[i])!=0)&&(m[nums[i]]!=0))
            return true;
        m[nums[i+1]]--;
        if(i+k+1<length)
            m[nums[i+k+1]]++;
    }
    return false;
}
};
