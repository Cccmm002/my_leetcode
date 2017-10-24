// Given an integer array nums, find the sum of the elements between indices i and j (i &le; j), inclusive.
//
// The update(i, val) function modifies nums by updating the element at index i to val.
//
// Example:
//
// Given nums = [1, 3, 5]
//
// sumRange(0, 2) -> 9
// update(1, 2)
// sumRange(0, 2) -> 8
//
//
//
// Note:
//
// The array is only modifiable by the update function.
// You may assume the number of calls to update and sumRange function is distributed evenly.


class NumArray {
private:
    vector<int> a, c;
    int n;
    
    inline int lowbit (int x) {
        return (x & -x);
    }
    
    int _sum(int x) {
        int res = 0;
        for(int i = x; i > 0; i -= lowbit(i)){
            res += c[i];
        }
        return res;    
    }
    
public:
    NumArray(vector<int> nums) {
        n = nums.size();
        if (n == 0) return;
        vector<int> va(n + 1);
        for (int i = 0; i < n; i++) va[i + 1] = nums[i];
        a = va;
        vector<int> vc(n + 1);
        vector<int> psum(n + 1);
        psum[1] = nums[0];
        for (int i = 2; i <= n; i++) psum[i] = nums[i - 1] + psum[i - 1];
        for (int i = 1; i <= n; i++) {
            vc[i] = psum[i] - psum[i - lowbit(i)];
        }
        c = vc;
    }
    
    void update(int i, int val) {
        int diff = val - a[i + 1];
        a[i + 1] = val;
        for(int t = i + 1; t <= n; t += lowbit(t)){
            c[t] += diff;
        }
    }
    
    int sumRange(int i, int j) {
        return _sum(j + 1) - _sum(i);
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray obj = new NumArray(nums);
 * obj.update(i,val);
 * int param_2 = obj.sumRange(i,j);
 */
