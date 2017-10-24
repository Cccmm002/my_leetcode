// Given an array of integers that is already sorted in ascending order, find two numbers such that they add up to a specific target number.
//
// The function twoSum should return indices of the two numbers such that they add up to the target, where index1 must be less than index2. Please note that your returned answers (both index1 and index2) are not zero-based.
//
// You may assume that each input would have exactly one solution and you may not use the same element twice.
//
//
// Input: numbers={2, 7, 11, 15}, target=9
// Output: index1=1, index2=2


class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int a = 0, b = n - 1;
        while (a < b) {
            int sum = numbers[a] + numbers[b];
            if (sum == target)
                return {a + 1, b + 1};
            if (sum < target)
                ++a;
            else
                --b;
        }
        return {a + 1, b + 1};
    }
};