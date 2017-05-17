// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// Example:
//
// Given nums = [-2, 0, 3, -5, 2, -1]
//
// sumRange(0, 2) -> 1
// sumRange(2, 5) -> -1
// sumRange(0, 5) -> -3
//
//
//
// Note:
//
// You may assume that the array does not change.
// There are many calls to sumRange function.


class NumArray {
private:
    vector<int> sums;
    vector<int> _nums;
public:
    NumArray(vector<int> &nums) {
        int len=nums.size();
        sums.push_back(0);
        for(int i=1;i<=len;i++)
            sums.push_back(sums[i-1]+nums[i-1]);
        _nums=nums;
    }

    int sumRange(int i, int j) {
        return sums[j]-sums[i]+_nums[j];
    }
};

//a[0]+a[1]+a[2]=s[3]
//a[0]+a[1]+a[2]+a[3]+a[4]+a[5]=s[6]
//s[6]-s[3]=a[3]+a[4]+a[5]


// Your NumArray object will be instantiated and called as such:
// NumArray numArray(nums);
// numArray.sumRange(0, 1);
// numArray.sumRange(1, 2);
