// Given n nodes labeled from 0 to n - 1 and a list of undirected edges (each edge is a pair of nodes), write a function to check whether these edges make up a valid tree.
//
//
//
// For example:
//
//
// Given n = 5 and edges = [[0, 1], [0, 2], [0, 3], [1, 4]], return true.
//
//
// Given n = 5 and edges = [[0, 1], [1, 2], [2, 3], [1, 3], [1, 4]], return false.
//
//
//
// Note: you can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.


class Solution {
public:
    bool validTree(int n, vector<pair<int, int>>& edges) {
        queue<int> q;
        q.push(0);
        unordered_map<int, int> parents;
        while (!q.empty()) {
            int cur = q.front();
            q.pop();
            int curpar = parents.find(cur) == parents.end() ? -1 : parents[cur];
            for (pair<int, int> p : edges) {
                if (p.first != cur && p.second != cur) continue;
                if (p.first == cur) {
                    if (p.second == curpar) continue;
                    if (parents.find(p.second) != parents.end()) {
                        return false;
                    }
                    else {
                        int next = p.second;
                        parents[next] = cur;
                        q.push(next);
                    }
                }
                else {
                    if (p.first == curpar) continue;
                    if (parents.find(p.first) != parents.end()) {
                        return false;
                    }
                    else {
                        int next = p.first;
                        parents[next] = cur;
                        q.push(next);
                    }
                }
            }
        }
        bool valid = true;
        for (int i = 1; i < n; i++) {
            if (parents.find(i) == parents.end()) {
                valid = false;
                break;
            }
        }
        return valid;
    }
};
