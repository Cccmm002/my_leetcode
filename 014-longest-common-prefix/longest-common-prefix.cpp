// Write a function to find the longest common prefix string amongst an array of strings.


class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
    int size=strs.size();
    if (size==0) 
        return "";
    int minlen=INT32_MAX;
    for(int i=0;i<size;i++){
        if(minlen>strs[i].length())
            minlen=strs[i].length();
    }
    string res="";
    for(int i=0;i<minlen;i++){
        bool flag=true;
        char c=strs[0][i];
        for(int j=1;j<size;j++){
            if(strs[j][i]!=c){
                flag=false;
                break;
            }
        }
        if(flag)
            res+=c;
        else
            break;
    }
    return res;
}
};
