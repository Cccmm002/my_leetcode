// A binary watch has 4 LEDs on the top which represent the hours (0-11), and the 6 LEDs on the bottom represent the minutes (0-59).
// Each LED represents a zero or one, with the least significant bit on the right.
//
// For example, the above binary watch reads "3:25".
//
// Given a non-negative integer n which represents the number of LEDs that are currently on, return all possible times the watch could represent.
//
// Example:
// Input: n = 1Return: ["1:00", "2:00", "4:00", "8:00", "0:01", "0:02", "0:04", "0:08", "0:16", "0:32"]
//
//
// Note:
//
// The order of output does not matter.
// The hour must not contain a leading zero, for example "01:00" is not valid, it should be "1:00".
// The minute must be consist of two digits and may contain a leading zero, for example "10:2" is not valid, it should be "10:02".
//
//


class Solution {
private:
    vector<int> getNumbers(int num, int largestAmount){
        vector<int> res;
        if(num>largestAmount) return res;
        if(largestAmount==1){
            if(num==0) res.push_back(0);
            if(num==1) res.push_back(1);
            return res;
        }
        vector<int> v;
        v=getNumbers(num,largestAmount-1);
        for(int i:v)
            res.push_back(i<<1);
        v=getNumbers(num-1,largestAmount-1);
        for(int i:v)
            res.push_back((i<<1)+1);
        return res;
    }
public:
    vector<string> readBinaryWatch(int num) {
        vector<string> res;
        for(int i=0;i<=4;i++){
            if(i>num) break;
            vector<int> hours=getNumbers(i,4);
            vector<int> minutes=getNumbers(num-i,6);
            for(int h:hours){
                if(h>=12) continue;
                for(int m:minutes){
                    if(m>=60) continue;
                    string sm=to_string(m);
                    if(sm.length()==1) sm="0"+sm;
                    res.push_back(to_string(h)+":"+sm);
                }
            }
        }
        sort(res.begin(),res.end());
        return res;
    }
};
