//
// There are N students in a class. Some of them are friends, while some are not. Their friendship is transitive in nature. For example, if A is a direct friend of B, and B is a direct friend of C, then A is an indirect friend of C. And we defined a friend circle is a group of students who are direct or indirect friends.
//
//
//
// Given a N*N matrix M representing the friend relationship between students in the class. If M[i][j] = 1, then the ith and jth students are direct friends with each other, otherwise not. And you have to output the total number of friend circles among all the students.
//
//
// Example 1:
//
// Input: 
// [[1,1,0],
//  [1,1,0],
//  [0,0,1]]
// Output: 2
// Explanation:The 0th and 1st students are direct friends, so they are in a friend circle. The 2nd student himself is in a friend circle. So return 2.
//
//
//
// Example 2:
//
// Input: 
// [[1,1,0],
//  [1,1,1],
//  [0,1,1]]
// Output: 1
// Explanation:The 0th and 1st students are direct friends, the 1st and 2nd students are direct friends, so the 0th and 2nd students are indirect friends. All of them are in the same friend circle, so return 1.
//
//
//
//
// Note:
//
// N is in range [1,200].
// M[i][i] = 1 for all students.
// If M[i][j] = 1, then M[j][i] = 1.
//
//


class UnionFind {
private:
    int *parents;
    int num;

public:
    UnionFind(int n) {
        num = n;
        parents = new int[n];
        for(int i=0;i<n;i++)
            parents[i] = i;
    }
    
    int findSet(int n) {
        if(parents[n] == n)
            return n;
        int p = findSet(parents[n]);
        parents[n] = p;
        return p;
    }
    
    void connect(int x, int y) {
        int a = findSet(x);
        int b = findSet(y);
        if (a != b)
            parents[a] = b;
    }
    
    void print() {
        for(int i=0;i<num;i++)
            cout<<parents[i]<<' ';
        cout<<endl;
    }
    
    int count() {
        int *c = new int[this->num];
        for(int i = 0;i<num;i++)
            c[i] = 0;
        for(int i=0;i<num;i++)
            c[this->findSet(i)]++;
        int sum = 0;
        for(int i=0;i<num;i++)
            sum+=c[i]>0?1:0;
        delete[] c;
        return sum;
    }
    
    ~UnionFind() {
        delete[] parents;
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& M) {
        int n = M.size();
        if(n<=0) return 0;
        UnionFind *uf = new UnionFind(n);
        for(int i=0;i<n;i++) {
            for(int j=i+1;j<n;j++) {
                if (M[i][j] == 1) {
                    uf->connect(i,j);
                }
            }
        }
        int res = uf->count();
        delete uf;
        return res;
    }
};
