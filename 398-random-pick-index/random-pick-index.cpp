// Given an array of integers with possible duplicates, randomly output the index of a given target number. You can assume that the given target number must exist in the array.
//
//
//
// Note:
// The array size can be very large. Solution that uses too much extra space will not pass the judge.
//
//
// Example:
//
// int[] nums = new int[] {1,2,3,3,3};
// Solution solution = new Solution(nums);
//
// // pick(3) should return either index 2, 3, or 4 randomly. Each index should have equal probability of returning.
// solution.pick(3);
//
// // pick(1) should return 0. Since in the array only nums[0] is equal to 1.
// solution.pick(1);


class Solution {
private:
    std::random_device rd;
    std::mt19937_64 gen;
    vector<int> v;
    
public:
    Solution(vector<int> nums) {
        std::mt19937_64 generator(rd());
        gen = generator;
        v = nums;
    }
    
    int pick(int target) {
        unsigned long long res = 0;
        unsigned long long n = 0;
        unsigned long long index = 0;
        auto it = v.begin();
        while (it != v.end()) {
            if (*it == target) {
                n++;
                std::uniform_int_distribution<unsigned long long> dis(1, n);
                unsigned long long rn = dis(gen);
                if (rn == 1) {
                    res = index;
                }
            }
            it++;
            index++;
        }
        return (int)res;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution obj = new Solution(nums);
 * int param_1 = obj.pick(target);
 */
