// Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
// If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
// The replacement must be in-place and use only constant extra memory.
//
// Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//
// 1,2,3 → 1,3,2
// 3,2,1 → 1,2,3
// 1,1,5 → 1,5,1
//


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
};
