// Equations are given in the format A / B = k, where  A and B are variables represented as strings, and k is a real number (floating point number). Given some queries, return the answers. If the answer does not exist, return -1.0.
//
// Example:
// Given  a / b = 2.0, b / c = 3.0. queries are:  a / c = ?,  b / a = ?, a / e = ?,  a / a = ?, x / x = ? . return  [6.0, 0.5, -1.0, 1.0, -1.0 ].
//
//
// The input is:  vector&lt;pair&lt;string, string&gt;&gt; equations, vector&lt;double&gt;&amp; values, vector&lt;pair&lt;string, string&gt;&gt; queries , where equations.size() == values.size(), and the values are positive. This represents the equations. Return  vector&lt;double&gt;.
//
//
// According to the example above:
// equations = [ ["a", "b"], ["b", "c"] ],
// values = [2.0, 3.0],
// queries = [ ["a", "c"], ["b", "a"], ["a", "e"], ["a", "a"], ["x", "x"] ]. 
//
//
//
// The input is always valid. You may assume that evaluating the queries will result in no division by zero and there is no contradiction.


class Solution {
private:
    typedef struct Node {
        string name;
        map<string,double> m;
        Node(string n):name(n){}
    }*pNode;
    
    double calc(string a,string b, map<string,pNode> &m, set<string> &visited) {
        auto _it=m.find(a);
        if(_it==m.end()) return -1;
        if(a==b) return 1;
        if(visited.find(a)!=visited.end()) return -1;
        visited.insert(a);
        pNode start=_it->second;
        auto it=start->m.begin();
        while(it!=start->m.end()) {
            double r=calc(it->first,b,m,visited);
            if(r>0) return r*(it->second);
            it++;
        }
        return -1;
    }
public:
    vector<double> calcEquation(vector<pair<string, string>> equations, vector<double>& values, vector<pair<string, string>> queries) {
        map<string,pNode> m;
        int num=equations.size();
        for(int i=0;i<num;i++) {
            string a=equations[i].first;
            string b=equations[i].second;
            pNode na,nb;
            auto it=m.find(a);
            if(it==m.end()) {na=new Node(a); m[a]=na;}
            else na=it->second;
            it=m.find(b);
            if(it==m.end()) {nb=new Node(b); m[b]=nb;}
            else nb=it->second;
            na->m[b]=values[i];
            nb->m[a]=1.0/values[i];
        }
        
        vector<double> res;
        for(pair<string,string> p:queries) {
            string a=p.first;
            string b=p.second;
            set<string> v;
            double z=calc(a,b,m,v);
            res.push_back(z);
        }
        return res;
    }
};
