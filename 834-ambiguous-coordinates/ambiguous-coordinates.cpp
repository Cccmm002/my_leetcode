// We had some 2-dimensional coordinates, like "(1, 3)" or "(2, 0.5)".  Then, we removed all commas, decimal points, and spaces, and ended up with the string S.  Return a list of strings representing all possibilities for what our original coordinates could have been.
//
// Our original representation never had extraneous zeroes, so we never started with numbers like "00", "0.0", "0.00", "1.0", "001", "00.01", or any other number that can be represented with less digits.  Also, a decimal point within a number never occurs without at least one digit occuring before it, so we never started with numbers like ".1".
//
// The final answer list can be returned in any order.  Also note that all coordinates in the final answer have exactly one space between them (occurring after the comma.)
//
//
// Example 1:
// Input: "(123)"
// Output: ["(1, 23)", "(12, 3)", "(1.2, 3)", "(1, 2.3)"]
//
//
//
// Example 2:
// Input: "(00011)"
// Output:  ["(0.001, 1)", "(0, 0.011)"]
// Explanation: 
// 0.0, 00, 0001 or 00.01 are not allowed.
//
//
//
// Example 3:
// Input: "(0123)"
// Output: ["(0, 123)", "(0, 12.3)", "(0, 1.23)", "(0.1, 23)", "(0.1, 2.3)", "(0.12, 3)"]
//
//
//
// Example 4:
// Input: "(100)"
// Output: [(10, 0)]
// Explanation: 
// 1.0 is not allowed.
//
//
//  
//
// Note: 
//
//
// 	4 <= S.length <= 12.
// 	S[0] = "(", S[S.length - 1] = ")", and the other elements in S are digits.
//
//
//  


class Solution {
private:
    vector<string> oneNum(string s) {
        int n = s.size();
        vector<string> res;
        if (stoi(s) > 0 && s[0] != '0') res.push_back(s);
        else if (stoi(s) == 0 && s.size() == 1) res.push_back(s);
        for (int i=0;i<n-1;i++) {
            string left = s.substr(0, i+1);
            string right = s.substr(i+1, n-1-i);
            if (stoi(right) <= 0) continue;
            if (right[right.size() - 1] == '0') continue;
            if (stoi(left) > 0 && left[0] == '0') continue;
            if (stoi(left) == 0 && left.size() > 1) continue;
            res.push_back(left + "." + right);
        }
        return res;
    }
    
public:
    vector<string> ambiguousCoordinates(string S) {
        vector<string> res;
        string s = S.substr(1, S.size() - 2);
        int n = s.size();
        for (int i = 0; i < n - 1; i++) {
            string left = s.substr(0, i+1);
            string right = s.substr(i+1, n-1-i);
            vector<string> lv = oneNum(left);
            if (lv.size() == 0) continue;
            vector<string> rv = oneNum(right);
            if (rv.size() == 0) continue;
            for (int l = 0;l<lv.size();l++) {
                for (int r=0;r<rv.size();r++) {
                    res.push_back("(" + lv[l] + ", " + rv[r] + ")");
                }
            }
        }
        return res;
    }
};
