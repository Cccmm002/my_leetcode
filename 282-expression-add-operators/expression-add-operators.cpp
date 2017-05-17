// Given a string that contains only digits 0-9 and a target value, return all possibilities to add binary operators (not unary) +, -, or * between the digits so they evaluate to the target value.
//
//
// Examples: 
// "123", 6 -> ["1+2+3", "1*2*3"] 
// "232", 8 -> ["2*3+2", "2+3*2"]
// "105", 5 -> ["1*0+5","10-5"]
// "00", 0 -> ["0+0", "0-0", "0*0"]
// "3456237490", 9191 -> []
//
//
// Credits:Special thanks to @davidtan1890 for adding this problem and creating all test cases.


class Solution {
private:
    void calc(string current, string num, int pointer, long long cur_result, int target, long long multi, vector<string> &result) {
        int len_num = num.size();
        if(pointer >= len_num) {
            if (target == cur_result)
                result.push_back(current);
            return;
        }
        int loop_upper = num[pointer] == '0' ? pointer + 1 : len_num;
        for (int i = pointer; i < loop_upper; i++) {
            string sn = num.substr(pointer, i-pointer+1);
            long long n = stoll(sn);
            if (pointer == 0) {
                calc(sn, num, i+1, n, target, n, result);
            }
            else {
                calc(current+"+"+sn, num, i+1, cur_result+n, target, n, result);
                calc(current+"-"+sn, num, i+1, cur_result-n, target, 0-n, result);
                calc(current+"*"+sn, num, i+1, cur_result-multi+multi*n, target, n*multi, result);
            }
        }
    }
    
public:
    vector<string> addOperators(string num, int target) {
        vector<string> res;
        calc("", num, 0, 0, target, 0, res);
        return res;
    }
};
