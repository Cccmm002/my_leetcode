// Given a set of distinct positive integers, find the largest subset such that every pair (Si, Sj) of elements in this subset satisfies: Si % Sj = 0 or Sj % Si = 0.
//
//
// If there are multiple solutions, return any subset is fine.
//
//
// Example 1:
//
// nums: [1,2,3]
//
// Result: [1,2] (of course, [1,3] will also be ok)
//
//
//
// Example 2:
//
// nums: [1,2,4,8]
//
// Result: [1,2,4,8]
//
//
//
// Credits:Special thanks to @Stomach_ache for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int len=nums.size();
        vector<int> res;
        if(len==0) return res;
        sort(nums.begin(),nums.end());
        int *s=new int[len];
        int *prev=new int[len];
        int max=1; int max_index=0;
        for(int i=0;i<len;i++) {
            s[i]=1;
            prev[i]=-1;
            for(int j=0;j<i;j++) {
                if(nums[i]%nums[j]!=0)
                    continue;
                int cur=s[j]+1;
                if(cur>s[i]){
                    s[i]=cur;
                    prev[i]=j;
                }
            }
            if(s[i]>max) {
                max=s[i];
                max_index=i;
            }
        }
        int index=max_index;
        while(index!=-1) {
            res.push_back(nums[index]);
            index=prev[index];
        }
        delete[] s; delete[] prev;
        sort(res.begin(),res.end());
        return res;
    }
};
