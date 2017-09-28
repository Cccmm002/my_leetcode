// There are two sorted arrays nums1 and nums2 of size m and n respectively.
//
// Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).
//
// Example 1:
//
// nums1 = [1, 3]
// nums2 = [2]
//
// The median is 2.0
//
//
//
// Example 2:
//
// nums1 = [1, 2]
// nums2 = [3, 4]
//
// The median is (2 + 3)/2 = 2.5


class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int l1 = nums1.size();
        int l2 = nums2.size();
        int m, n;
        vector<int> a, b;
        if (l2 >= l1) {
            a = nums1; b = nums2;
            m = l1; n = l2;
        }
        else {
            a = nums2; b = nums1;
            m = l2; n = l1;
        }
        if (m == 0) {
            if ((n&1) == 1) return b[n/2];
            else return ((double)(b[n/2 - 1] + b[n/2]))/2.0;
        }
        int il = 0, ir = m;
        while (il <= ir) {
            int i = (il + ir)/2;
            int j = (m + n + 1)/2 - i;
            if (i < m && b[j - 1] > a[i]) il = i + 1;
            else if(i > 0 && a[i - 1] > b[j]) ir = i - 1;
            else {
                int maxLeft, minRight;
                if (i == 0) maxLeft = b[j - 1];
                else if(j == 0) maxLeft = a[i - 1];
                else maxLeft = max(a[i - 1], b[j - 1]);
                if (i == m) minRight = b[j];
                else if(j == n) minRight = a[i];
                else minRight = min(a[i], b[j]);
                if (((m + n) & 1) == 1) return maxLeft;
                else return ((double)(maxLeft + minRight))/2.0;
            }
        }
        return 0.0;
    }
};
