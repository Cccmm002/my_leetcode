// Given an array nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position. Return the max sliding window.
//
// Example:
//
//
// Input: nums = [1,3,-1,-3,5,3,6,7], and k = 3
// Output: [3,3,5,5,6,7] 
// Explanation: 
//
// Window position                Max
// ---------------               -----
// [1  3  -1] -3  5  3  6  7       3
//  1 [3  -1  -3] 5  3  6  7       3
//  1  3 [-1  -3  5] 3  6  7       5
//  1  3  -1 [-3  5  3] 6  7       5
//  1  3  -1  -3 [5  3  6] 7       6
//  1  3  -1  -3  5 [3  6  7]      7
//
//
// Note: 
// You may assume k is always valid, 1 ≤ k ≤ input array's size for non-empty array.
//
// Follow up:
// Could you solve it in linear time?
//


class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int length = nums.size();
        vector<int> result;
        if (length == 0) return result;
        if (k == 1) return nums;
        deque<int> dq;
        
        for (int i = 0; i < length; ++i) {
            if (i >= k) {
                if (dq.front() == nums[i - k]) 
                    dq.pop_front();
            }
            while (!dq.empty() && dq.back() < nums[i]) 
                dq.pop_back();
            dq.push_back(nums[i]);
            if (i >= k - 1)
                result.push_back(dq.front());
        }
        return result;
    }
};
