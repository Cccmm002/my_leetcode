// An undirected, connected tree with N nodes labelled 0...N-1 and N-1 edges are given.
//
// The ith edge connects nodes edges[i][0] and edges[i][1] together.
//
// Return a list ans, where ans[i] is the sum of the distances between node i and all other nodes.
//
// Example 1:
//
//
// Input: N = 6, edges = [[0,1],[0,2],[2,3],[2,4],[2,5]]
// Output: [8,12,6,10,10,10]
// Explanation: 
// Here is a diagram of the given tree:
//   0
//  / \
// 1   2
//    /|\
//   3 4 5
// We can see that dist(0,1) + dist(0,2) + dist(0,3) + dist(0,4) + dist(0,5)
// equals 1 + 1 + 2 + 2 + 2 = 8.  Hence, answer[0] = 8, and so on.
//
//
// Note: 1 <= N <= 10000


class Solution {
private:
    vector<int> count, below, res;
    int n;
    
    void dfs(int root, int prev, vector<vector<int>> &children) {
        int c = 1, r = 0;
        for (int i:children[root]) {
            if (i == prev) 
                continue;
            dfs(i, root, children);
            c += count[i];
            r += below[i];
        }
        below[root] = r + c - 1;
        count[root] = c;
    }
    
    void dfs2(int root, int parent, vector<vector<int>> &children) {
        if (parent != -1) {
            res[root] = res[parent] - count[root] + (n - count[root]);
        }
        for (int i:children[root]) {
            if (i != parent)
                dfs2(i, root, children);
        }
    }
    
public:
    vector<int> sumOfDistancesInTree(int N, vector<vector<int>>& edges) {
        vector<vector<int>> children(N);
        for (vector<int> &e:edges) {
            children[e[0]].push_back(e[1]);
            children[e[1]].push_back(e[0]);
        }
        this->n = N;
        this->count = vector<int>(N, 0);
        this->below = vector<int>(N, 0);
        this->res = vector<int>(N, 0);
        dfs(0, -1, children);
        res[0] = below[0];
        dfs2(0, -1, children);
        return res;
    }
};
