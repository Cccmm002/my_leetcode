// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Find all strobogrammatic numbers that are of length = n. 
// For example,
// Given n = 2, return ["11","69","88","96"].


class Solution {
private:
    vector<string> helper(int n) {
        if (n == 0) {
            vector<string> v = {""};
            return v;
        }
        if (n == 1) {
            vector<string> v = {"1", "8", "0"};
            return v;
        }
        string addingTwo[5][2] = {{"1", "1"}, {"6", "9"}, {"8", "8"}, {"9", "6"}, {"0", "0"}};
        string addingMiddle[3] = {"0", "1", "8"};
        if (n%2 == 0) {
            vector<string> prev = helper(n - 2);
            vector<string> res;
            for(string str : prev) {
                for (int i = 0; i < 5; i++) {
                    string new_str = addingTwo[i][0] + str + addingTwo[i][1];
                    res.push_back(new_str);
                }
            }
            return res;
        }
        else {
            vector<string> prev = helper(n - 1);
            vector<string> res;
            int half = (n - 1)/2;
            for(string str : prev) {
                string first = str.substr(0, half);
                string second = str.substr(half, half);
                for (int i = 0; i < 3; i++) {
                    string new_str = first + addingMiddle[i] + second;
                    res.push_back(new_str);
                }
            }
            return res;
        }
    }
    
public:
    vector<string> findStrobogrammatic(int n) {
        if (n == 0) {
            vector<string> v = {""};
            return v;
        }
        if (n == 1) {
            vector<string> v = {"1", "8", "0"};
            return v;
        }
        vector<string> v = helper(n);
        vector<string> res;
        for (string str : v) {
            if (str[0] != '0') res.push_back(str);
        }
        return res;
    }
};
