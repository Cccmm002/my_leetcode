// You are given a string representing an attendance record for a student. The record only contains the following three characters:
//
//
//
// 'A' : Absent. 
// 'L' : Late.
//  'P' : Present. 
//
//
//
//
// A student could be rewarded if his attendance record doesn't contain more than one 'A' (absent) or more than two continuous 'L' (late).    
//
// You need to return whether the student could be rewarded according to his attendance record.
//
// Example 1:
//
// Input: "PPALLP"
// Output: True
//
//
//
// Example 2:
//
// Input: "PPALLL"
// Output: False
//
//
//
//
//


class Solution {
public:
    bool checkRecord(string s) {
        int len = s.size();
        int a_count = 0;
        int l_count = 0;
        for (int i = 0; i < len; i++) {
            char c = s[i];
            if (c != 'L') l_count = 0;
            if (c == 'A') {
                a_count++;
                if (a_count > 1) return false;
            }
            if (c == 'L') {
                l_count++;
                if (l_count > 2) return false;
            }
        }
        return true;
    }
};
