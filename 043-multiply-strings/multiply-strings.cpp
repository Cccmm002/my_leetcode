// Given two non-negative integers num1 and num2 represented as strings, return the product of num1 and num2, also represented as a string.
//
// Example 1:
//
//
// Input: num1 = "2", num2 = "3"
// Output: "6"
//
// Example 2:
//
//
// Input: num1 = "123", num2 = "456"
// Output: "56088"
//
//
// Note:
//
//
// 	The length of both num1 and num2 is < 110.
// 	Both num1 and num2 contain only digits 0-9.
// 	Both num1 and num2 do not contain any leading zero, except the number 0 itself.
// 	You must not use any built-in BigInteger library or convert the inputs to integer directly.
//
//


class Solution {
public:
    string multiply(string num1, string num2) {
        int len1=num1.length();
        int len2=num2.length();
        vector<vector<int>> adder;
        for(int i=len2-1;i>=0;i--){
            vector<int> res;
            for(int j=0;j<len2-i-1;j++)
                res.push_back(0);
            int multiplier=num2[i]-'0';
            int indent=0;
            for(int j=len1-1;j>=0;j--){
                int mul=num1[j]-'0';
                int prod=mul*multiplier+indent;
                indent=prod/10;
                res.push_back(prod%10);
            }
            if(indent!=0)
                res.push_back(indent);
            adder.push_back(res);
        }
        vector<int> sum;
        int indent=0;
        for(int i=0;i<len1+len2;i++){
            int s=indent;
            for(int j=0;j<adder.size();j++){
                if(i<adder[j].size())
                    s+=adder[j][i];
            }
            sum.insert(sum.begin(),s%10);
            indent=s/10;
        }
        auto it=sum.begin();
        while(it!=sum.end()-1){
            if(*it==0 && *(it+1)==0)
                sum.erase(it);
            else
                break;
        }
        if(sum[0]==0 && sum.size()>1) sum.erase(sum.begin());
        string res="";
        for(int i=0;i<sum.size();i++)
            res+=to_string(sum[i]);
        return res;
    }
};
