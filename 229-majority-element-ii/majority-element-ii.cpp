// Given an integer array of size n, find all elements that appear more than &lfloor; n/3 &rfloor; times. The algorithm should run in linear time and in O(1) space.


class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        vector<int> res;
        int len=nums.size();
        if(len==0) return res;
        if(len==1) {res.push_back(nums[0]); return res;}
        
        int a=nums[0];
        int b=nums[1];
        int countA=0,countB=0;
        for(int i=0;i<len;i++){
            int n=nums[i];
            if(a==n) countA++;
            else if(b==n) countB++;
            else if(countA==0) {countA++; a=n;}
            else if(countB==0) {countB++; b=n;}
            else {countA--; countB--;}
        }
        int cca=0,ccb=0;
        for(int i=0;i<len;i++){
            if(nums[i]==a)
                cca++;
            else if(nums[i]==b)
                ccb++;
        }
        if(cca>len/3)
            res.push_back(a);
        if(ccb>len/3)
            res.push_back(b);
        sort(res.begin(),res.end());
        return res;
    }
};
