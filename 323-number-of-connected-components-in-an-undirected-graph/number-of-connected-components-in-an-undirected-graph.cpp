// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to find the number of connected components in an undirected graph.
//
//
//
//     Example 1:
//
//
//      0          3
//      |          |
//      1 --- 2    4
//
//
//     Given n = 5 and edges = [[0, 1], [1, 2], [3, 4]], return 2.
//
//
//     Example 2:
//
//
//      0           4
//      |           |
//      1 --- 2 --- 3
//
//
//     Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [3, 4]], return 1.
//
//
//
// Note:
// You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


class Solution {
private:
    vector<int> group;
    
    int find(int node) {
        if (node == group[node]) return node;
        int root = find(group[node]);
        group[node] = root;
        return root;
    }
    
    void _union(int a, int b) {
        int rootA = find(a);
        int rootB = find(b);
        if (rootA == rootB) return;
        group[rootA] = rootB;
    }
    
public:
    int countComponents(int n, vector<pair<int, int>>& edges) {
        vector<int> v(n);
        for (int i = 0; i < n; i++) v[i] = i;
        group = v;
        for (pair<int, int> p : edges) {
            _union(p.first, p.second);
        }
        vector<bool> occupied(n, false);
        for (int i = 0; i < n; i++) {
            occupied[find(i)] = true;
        }
        int res = 0;
        for (int i = 0; i < n; i++) {
            if (occupied[i]) res++;
        }
        return res;
    }
};
