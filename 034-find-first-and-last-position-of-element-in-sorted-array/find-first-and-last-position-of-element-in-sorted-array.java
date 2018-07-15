// Given an array of integers nums sorted in ascending order, find the starting and ending position of a given target value.
//
// Your algorithm's runtime complexity must be in the order of O(log n).
//
// If the target is not found in the array, return [-1, -1].
//
// Example 1:
//
//
// Input: nums = [5,7,7,8,8,10], target = 8
// Output: [3,4]
//
// Example 2:
//
//
// Input: nums = [5,7,7,8,8,10], target = 6
// Output: [-1,-1]
//


public class Solution {
    public int[] searchRange(int[] nums, int target) {
        int len=nums.length;
        int[] res=new int[2];
        res[0]=-1; res[1]=-1;
        if(len==1) {
            if(nums[0]==target){
                res[0]=0; res[1]=0;
                return res;
            }
            else
                return res;
        }
        int begin=0;
        int end=len;
        while(begin<end-1) {
            int mid=(begin+end)/2;
            if(nums[mid]<target)
                begin=mid;
            else
                end=mid;
            //if(begin==end-1)
            //    break;
        }
        if(nums[begin]==target)
            res[0]=begin;
        else if(end<len && nums[end]==target)
            res[0]=end;
        else
            return res;
        begin=0;
        end=len;
        while(begin<end-1) {
            int mid=(begin+end)/2;
            if(nums[mid]<=target)
                begin=mid;
            else
                end=mid;
            //if(begin==end-1)
            //    break;
        }
        res[1]=begin;
        return res;
    }
}
