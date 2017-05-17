// Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//
//
// For example, given n = 3, a solution set is:
//
//
// [
//   "((()))",
//   "(()())",
//   "(())()",
//   "()(())",
//   "()()()"
// ]


class Solution {
private:
    struct genPair{
        int left,right;
        genPair(int l,int r):left(l),right(r) {}
    };
    
struct KeyHash {
    std::size_t operator()(const genPair& k) const {
        return k.left ^ k.right;
    }
};

struct KeyEqual {
    bool operator()(const genPair& a, const genPair& b) const{
        if (a.left == b.left && a.right == b.right)
            return true;
        else
            return false;
    }
};
    
public:
    vector<string> gen(int left, int right, unordered_map<genPair,vector<string>, KeyHash, KeyEqual> &m) {
        genPair gp(left,right);
        auto it=m.find(gp);
        if(it!=m.end()) return it->second;
        
        vector<string> res;
        if(left>0){
            vector<string> l=gen(left-1,right,m);
            for(string s:l)
                res.push_back("("+s);
        }
        if(right>left){
            vector<string> r=gen(left,right-1,m);
            for(string s:r)
                res.push_back(")"+s);
        }
        if(right==0)
            res.push_back("");
        m[gp]=res;
        return res;
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if(n==0) return res;
        if(n==1){
            res.push_back("()");
            return res;
        }
        unordered_map<genPair,vector<string>, KeyHash, KeyEqual> m;
        return gen(n,n,m);
    }
};
