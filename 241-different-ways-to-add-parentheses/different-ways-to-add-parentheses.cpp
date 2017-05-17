// Given a string of numbers and operators, return all possible results from computing all the different possible ways to group numbers and operators. The valid operators are +, - and *.
//
// Example 1
// Input: "2-1-1". 
// ((2-1)-1) = 0
// (2-(1-1)) = 2
// Output: [0, 2]
//
// Example 2
// Input: "2*3-4*5" 
// (2*(3-(4*5))) = -34
// ((2*3)-(4*5)) = -14
// ((2*(3-4))*5) = -10
// (2*((3-4)*5)) = -10
// (((2*3)-4)*5) = 10
// Output: [-34, -14, -10, -10, 10] 
//
// Credits:Special thanks to @mithmatt for adding this problem and creating all test cases.


class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        int len = input.size();
        vector<int> res;
        for(int i = 0; i < len; i++) {
            char c = input[i];
            if(c != '+' && c != '-' && c != '*')
                continue;
            vector<int> left = diffWaysToCompute(input.substr(0, i));
            vector<int> right = diffWaysToCompute(input.substr(i + 1, len - i - 1));
            for(int j = 0; j < left.size(); j++) {
                for(int k = 0; k < right.size(); k++) {
                    int r;
                    if(c == '+')
                        r = left[j] + right[k];
                    if(c == '-')
                        r = left[j] - right[k];
                    if(c == '*')
                        r = left[j] * right[k];
                    res.push_back(r);
                }
            }
        }
        if(res.size() == 0) {
            res.push_back(stoi(input));
        }
        return res;
    }
};
