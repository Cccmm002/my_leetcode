// You are playing the following Flip Game with your friend: Given a string that contains only these two characters: + and -, you and your friend take turns to flip two consecutive "++" into "--". The game ends when a person can no longer make a move and therefore the other person will be the winner.
//
// Write a function to determine if the starting player can guarantee a win.
//
// Example:
//
//
// Input: s = "++++"
// Output: true 
// Explanation: The starting player can guarantee a win by flipping the middle "++" to become "+--+".
//
//
// Follow up:
// Derive your algorithm's runtime complexity.
//


class Solution {
private:
    bool next(string s) {  //true: starter round
        vector<string> res;
        int len = s.size();
        for (int i = 0; i < len - 1; i++) {
            if (s[i] == '+' && s[i + 1] == '+') {
                string ns = s;
                ns[i] = '-';
                ns[i + 1] = '-';
                res.push_back(ns);
            }
        }
        for (string str : res) {
            if (!next(str)) return true;
        }
        return false;
    }
    
public:
    bool canWin(string s) {
        return next(s);
    }
};
