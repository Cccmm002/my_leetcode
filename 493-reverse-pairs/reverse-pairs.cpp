// Given an array nums, we call (i, j) an important reverse pair if i &lt; j and nums[i] &gt; 2*nums[j].
//
// You need to return the number of important reverse pairs in the given array.
//
// Example1:
//
// Input: [1,3,2,3,1]
// Output: 2
//
//
// Example2:
//
// Input: [2,4,3,5,1]
// Output: 3
//
//
// Note:
//
// The length of the given array will not exceed 50,000.
// All the numbers in the input array are in the range of 32-bit integer.


class Solution {
private:
    int calc(int begin, int end, vector<long long>& nums) {
        if (begin >= end) return 0;
        int mid = (begin + end)/2;
        int res = calc(begin, mid, nums) + calc(mid + 1, end, nums);
        int p1 = begin;
        int p2 = mid + 1;
        int pc = 0;
        vector<long long> cache(end - begin + 1);
        for (p1 = begin; p1 <= mid; p1++) {
            res += p2 - mid - 1;
            while (p2 <= end && nums[p1] > 2*nums[p2]) {
                res++;
                p2++;
            }
        }
        p1 = begin;
        p2 = mid + 1;
        while (p1 <= mid || p2 <= end) {
            if (p1 > mid) {
                cache[pc] = nums[p2];
                p2++;
            }
            else if(p2 > end) {
                cache[pc] = nums[p1];
                p1++;
            }
            else {
                if (nums[p1] < nums[p2]) {
                    cache[pc] = nums[p1];
                    p1++;
                }
                else {
                    cache[pc] = nums[p2];
                    p2++;
                }
            }
            pc++;
        }
        for (int i = 0; i < end - begin + 1; i++) {
            nums[begin + i] = cache[i];
        }
        //cout<<begin<<' '<<end<<' '<<res<<endl;
        return res;
    }
    
public:
    int reversePairs(vector<int>& nums) {
        int len = nums.size();
        if (len == 0) return 0;
        vector<long long> nn(len);
        for (int i = 0; i < len; i++) nn[i] = nums[i];
        return calc(0, len - 1, nn);
    }
};
