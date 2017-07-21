// A peak element is an element that is greater than its neighbors.
//
// Given an input array where num[i] &ne; num[i+1], find a peak element and return its index.
//
// The array may contain multiple peaks, in that case return the index to any one of the peaks is fine.
//
// You may imagine that num[-1] = num[n] = -&infin;.
//
// For example, in array [1, 2, 3, 1], 3 is a peak element and your function should return the index number 2.
//
// click to show spoilers.
//
// Note:
// Your solution should be in logarithmic complexity.
//
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int begin=0;
        int end=nums.size()-1;
        while(begin<end){
            int med=(begin+end)/2;
            if(nums[med]<nums[med+1])
                begin=med+1;
            else
                end=med;
        }
        return begin;
    }
};
