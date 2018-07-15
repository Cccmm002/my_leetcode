//
// You have 4 cards each containing a number from 1 to 9.  You need to judge whether they could operated through *, /, +, -, (, ) to get the value of 24.
//
//
// Example 1:
//
// Input: [4, 1, 8, 7]
// Output: True
// Explanation: (8-4) * (7-1) = 24
//
//
//
// Example 2:
//
// Input: [1, 2, 1, 2]
// Output: False
//
//
//
// Note:
//
// The division operator / represents real division, not integer division.  For example, 4 / (1 - 2/3) = 12.
// Every operation done is between two numbers.  In particular, we cannot use - as a unary operator.  For example, with [1, 1, 1, 1] as input, the expression -1 - 1 - 1 - 1 is not allowed.
// You cannot concatenate numbers together.  For example, if the input is [1, 2, 1, 2], we cannot write this as 12 + 12.
//
//
//


class Solution {
private:
    bool judge(vector<float>& nums) {
        int length = nums.size();
        if (length == 0) return false;
        if (length == 1) return abs(nums[0] - 24) < 0.01;
        for (int i = 0; i < length; ++i) {
            for (int j = 0; j < length; ++j) {
                if (i == j) continue;
                
                vector<float> next;
                for (int k = 0; k < length; ++k) {
                    if (k != i && k != j)
                        next.push_back(nums[k]);
                }
                
                float plus = nums[i] + nums[j];
                next.push_back(plus);
                if (judge(next)) return true;
                
                float mul = nums[i] * nums[j];
                next[next.size() - 1] = mul;
                if (judge(next)) return true;
                
                float minus = nums[i] - nums[j];
                next[next.size() - 1] = minus;
                if (judge(next)) return true;
                
                if (nums[j] != 0) {
                    float div = nums[i] / nums[j];
                    next[next.size() - 1] = div;
                    if (judge(next)) return true;
                }
            }
        }
        return false;
    }
    
public:
    bool judgePoint24(vector<int>& nums) {
        vector<float> float_nums = {nums[0], nums[1], nums[2], nums[3]};
        return judge(float_nums);
    }
};
