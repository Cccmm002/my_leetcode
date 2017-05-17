// Given a list of non negative integers, arrange them such that they form the largest number.
//
// For example, given [3, 30, 34, 5, 9], the largest formed number is 9534330.
//
// Note: The result may be very large, so you need to return a string instead of an integer.
//
// Credits:Special thanks to @ts for adding this problem and creating all test cases.


class Solution {
public:
    string largestNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(),
             [](const int &a, const int &b) -> bool {
                 string x = to_string(a);
                 string y = to_string(b);
                 int xl = x.size();
                 int yl = y.size();
                 int xp = 0;
                 int yp = 0;
                 while (true) {
                     int ax = x[xp] - '0';
                     int by = y[yp] - '0';
                     if (ax == by) {
                         if (xp == xl - 1 && yp == yl - 1) return false;
                         xp++;
                         if (xp == xl) xp = 0;
                         yp++;
                         if (yp == yl) yp = 0;
                     }
                     else {
                         return ax > by;
                     }
                 }
             });
        if (nums[0] == 0) return "0";
        string res = "";
        for (int i=0;i<nums.size();i++)
            res += to_string(nums[i]);
        return res;
    }
};
