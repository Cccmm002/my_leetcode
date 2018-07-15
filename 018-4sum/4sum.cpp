// Given an array nums of n integers and an integer target, are there elements a, b, c, and d in nums such that a + b + c + d = target? Find all unique quadruplets in the array which gives the sum of target.
//
// Note:
//
// The solution set must not contain duplicate quadruplets.
//
// Example:
//
//
// Given array nums = [1, 0, -1, 0, -2, 2], and target = 0.
//
// A solution set is:
// [
//   [-1,  0, 0, 1],
//   [-2, -1, 1, 2],
//   [-2,  0, 0, 2]
// ]
//
//


class Solution {
private:
    vector<vector<int>> twoSum(vector<int>& nums, int begin, int end, int target) {
        vector<vector<int>> result;
        int left = begin, right = end;
        while (left < right) {
            if (nums[left] + nums[right] == target) {
                vector<int> current = {nums[left], nums[right]};
                result.push_back(current);
                do {
                    ++left;
                } while (left < right && nums[left] == nums[left - 1]);
            }
            else if (nums[left] + nums[right] < target)
                ++left;
            else
                --right;
        }
        return result;
    }
    
    vector<vector<int>> kSum(vector<int>& nums, int begin, int end, int k, int target) {
        vector<vector<int>> result;
        if (end - begin + 1 < k) return result;
        if (k == 2) {
            return twoSum(nums, begin, end, target);
        }
        for (int i = begin; i <= end - k + 1; ++i) {
            if (i > begin && nums[i] == nums[i - 1]) continue;
            vector<vector<int>> nexts = kSum(nums, i + 1, end, k - 1, target - nums[i]);
            for (vector<int> v : nexts) {
                vector<int> nv = {nums[i]};
                for (int j = 0; j < v.size(); j++) nv.push_back(v[j]);
                result.push_back(nv);
            }
        }
        return result;
    }
    
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        int length = nums.size();
        vector<vector<int>> result;
        if (length < 4) return result;
        sort(nums.begin(), nums.end());
        return kSum(nums, 0, length - 1, 4, target);
    }
};
