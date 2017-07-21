// A strobogrammatic number is a number that looks the same when rotated 180 degrees (looked at upside down).
// Write a function to count the total strobogrammatic numbers that exist in the range of low <= num <= high.
// For example,
// Given low = "50", high = "100", return 3. Because 69, 88, and 96 are three strobogrammatic numbers.
//
//
// Note:
// Because the range might be a large number, the low and high numbers are represented as string.


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
    int strobogrammaticInRange(string low, string high) {
        int low_len = low.size();
        int high_len = high.size();
        int count = 0;
        for (int i = low_len; i <= high_len; ++i) {
            vector<string> v = helper(i);
            for (string str : v) {
                int len = str.size();
                if (len != 1 && str[0] == '0') continue;
                if (len > low_len && len < high_len) {
                    count++;
                    continue;
                }
                if (len == low_len && str.compare(low) < 0) continue;
                if (len == high_len && str.compare(high) > 0) continue;
                count++;
            }
        }
        return count;
    }
};
