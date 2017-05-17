// Given a collection of numbers that might contain duplicates, return all possible unique permutations.
//
//
//
// For example,
// [1,1,2] have the following unique permutations:
//
// [
//   [1,1,2],
//   [1,2,1],
//   [2,1,1]
// ]


class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int length=nums.size();
        if(length<2) return;
        int pa=length-2;
        int pb=length-1;
        while(pa>=0){
            if(nums[pa]<nums[pb])
                break;
            pa--;
            pb--;
        }
        if(pa>=0) {
            int pc = length - 1;
            while (pc > pa) {
                if (nums[pc] > nums[pa])
                    break;
                pc--;
            }
            int t = nums[pc];
            nums[pc] = nums[pa];
            nums[pa] = t;
        }
        vector<int> copy(nums.begin()+pb,nums.end());  //[pb],[pb+1],...,[length-1]
        for(int i=0;i<length-pb;i++)
            nums[i+pb]=copy[length-pb-1-i];
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        std::sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        res.clear();
        res.push_back(nums);
        while(1){
            vector<int> v(*(res.end()-1));
            nextPermutation(v);
            
            bool flag=true;
            for(int i=0;i<nums.size();i++){
                if(res[0][i]!=v[i]){
                    flag=false;
                    break;
                }
            }
            if(flag)
                break;
            else
                res.push_back(v);
        }
        return res;
    }
};
