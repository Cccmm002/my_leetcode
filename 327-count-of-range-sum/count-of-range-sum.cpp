// Given an integer array nums, return the number of range sums that lie in [lower, upper] inclusive.
//
//     Range sum S(i, j) is defined as the sum of the elements in nums between indices i and 
//     j (i ≤ j), inclusive.
//
//
//
//     Note:
//     A naive algorithm of O(n2) is trivial. You MUST do better than that.
//
//
//     Example:
//     Given nums = [-2, 5, -1], lower = -2, upper = 2,
//     Return 3.
//     The three ranges are : [0, 0], [2, 2], [0, 2] and their respective sums are: -2, -1, 2.
//
//
// Credits:Special thanks to @dietpepsi for adding this problem and creating all test cases.


class Solution {
private:
    int calc(int b, int e, long long *arr, int lower, int upper) {
        if (e - b <= 1) return 0;
        int mid = (b + e)/2;
        int res = calc(b, mid, arr, lower, upper) + calc(mid, e, arr, lower, upper);
        int p1 = mid;
        int p2 = mid;
        int pt = mid;
        long long *cache = new long long[e - b];
        int r = 0;
        for (int i = b; i < mid; i++) {
            while (p1 < e && arr[p1] - arr[i] < lower) p1++;
            while (p2 < e && arr[p2] - arr[i] <= upper) p2++;
            while (pt < e && arr[pt] < arr[i]) cache[r++] = arr[pt++];
            cache[r++] = arr[i];
            res += p2 - p1;
        }
        for (int i = 0; i < pt - b; i++) 
            arr[b + i] = cache[i];
        delete[] cache;
        return res;
    }
    
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        int len = nums.size();
        if (len == 0) return 0;
        long long *sum = new long long[len + 1];
        sum[0] = 0;
        for (int i = 0; i < len; i++)
            sum[i + 1] = sum[i] + nums[i];
        int res = calc(0, len + 1, sum, lower, upper);
        //for (int i = 0; i < len + 1; i++) cout<<sum[i]<<' ';
        //cout<<endl;
        delete[] sum;
        return res;
    }
};
