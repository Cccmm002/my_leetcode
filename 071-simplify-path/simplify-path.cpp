// Given an absolute path for a file (Unix-style), simplify it.
//
// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
//
//
// click to show corner cases.
//
// Corner Cases:
//
//
//
// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".


class Solution {
public:
    string simplifyPath(string path) {
        int pathLen=path.size();
        string curDir="";
        stack<string> s;
        for(int i=0;i<=pathLen;i++){
            char c=0;
            if(i!=pathLen) c=path[i];
            if((c>='a' && c<='z')||(c>='A' && c<='Z')||(c>='0' && c<='9')||c=='_'||c=='.'){
                curDir+=c;
                continue;
            }
            if(curDir!=""){
                if(curDir==".."){
                    if(s.size()!=0)
                        s.pop();
                }
                if(curDir!="." && curDir!="..")
                    s.push(curDir);
                curDir="";
                continue;
            }
            if(c=='/') continue;
        }
        //if(curDir!="") s.push(curDir);
        stack<string> sRes;
        while(!s.empty()){
            sRes.push(s.top());
            s.pop();
        }
        string res="/";
        while(!sRes.empty()){
            res+=sRes.top();
            sRes.pop();
            if(!sRes.empty())
                res+='/';
        }
        return res;
    }
};
