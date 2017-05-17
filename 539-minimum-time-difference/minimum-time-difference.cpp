// Given a list of 24-hour clock time points in "Hour:Minutes" format, find the minimum minutes difference between any two time points in the list. 
//
// Example 1:
//
// Input: ["23:59","00:00"]
// Output: 1
//
//
//
// Note:
//
// The number of time points in the given list is at least 2 and won't exceed 20000.
// The input time is legal and ranges from 00:00 to 23:59.


class Solution {
private:
    inline int transform(string t) {
        int h = stoi(t.substr(0, 2));
        int m = stoi(t.substr(3, 2));
        return h*60+m;
    }
    
public:
    int findMinDifference(vector<string>& timePoints) {
        vector<int> times;
        for(string s:timePoints) {
            times.push_back(transform(s));
        }
        int len = times.size();
        int res = 1500;
        for(int i=0; i<len; i++) {
            for(int j=i+1; j<len; j++) {
                int a = max(times[i], times[j]);
                int b = min(times[i], times[j]);
                int r = min(a-b, b+1440-a);
                res = min(r,res);
            }
        }
        return res;
    }
};
