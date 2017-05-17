// Given an array of integers, find if the array contains any duplicates. Your function should return true if any value appears at least twice in the array, and it should return false if every element is distinct.


class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        std::set<int> s;
        for(int i=0;i<nums.size();i++){
            std::set<int>::iterator it=s.find(nums[i]);
            if(it!=s.end())
                return true;
            else
                s.insert(nums[i]);
        }
        return false;
    }
};
