// There are a total of n courses you have to take, labeled from 0 to n - 1.
//
// Some courses may have prerequisites, for example to take course 0 you have to first take course 1, which is expressed as a pair: [0,1]
//
//
// Given the total number of courses and a list of prerequisite pairs, is it possible for you to finish all courses?
//
//
// For example:
// 2, [[1,0]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0. So it is possible.
//
// 2, [[1,0],[0,1]]
// There are a total of 2 courses to take. To take course 1 you should have finished course 0, and to take course 0 you should also have finished course 1. So it is impossible.
//
// Note:
//
// The input prerequisites is a graph represented by a list of edges, not adjacency matrices. Read more about how a graph is represented.
// You may assume that there are no duplicate edges in the input prerequisites.
//
//
//
// click to show more hints.
//
// Hints:
//
// This problem is equivalent to finding if a cycle exists in a directed graph. If a cycle exists, no topological ordering exists and therefore it will be impossible to take all courses.
// Topological Sort via DFS - A great video tutorial (21 minutes) on Coursera explaining the basic concepts of Topological Sort.
// Topological sort could also be done via BFS.


class Solution {
public:
typedef struct Node{
    int num;
    int inDegree;
    vector<Node*> nextList;
    bool inGraph;

    Node(int n){
        num=n;
        inDegree=0;
        inGraph=true;
        nextList.clear();
    }
}*pNode;

bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
    vector<Node> nodes;
    for(int i=0;i<numCourses;i++)
        nodes.push_back(Node(i));
    int num_pre=prerequisites.size();
    for(int i=0;i<num_pre;i++) {
        nodes[prerequisites[i].second].nextList.push_back(&(nodes[prerequisites[i].first]));
        nodes[prerequisites[i].first].inDegree++;
    }
    stack<pNode> s;
    for(int i=0;i<numCourses;i++){
        if(nodes[i].inDegree==0)
            s.push(&nodes[i]);
    }
    while(!s.empty()){
        pNode cur=s.top();
        s.pop();
        cur->inGraph=false;
        for(int i=0;i<cur->nextList.size();i++){
            pNode n=cur->nextList[i];
            n->inDegree--;
            if(n->inDegree==0)
                s.push(n);
        }
    }
    for(int i=0;i<numCourses;i++){
        if(nodes[i].inGraph)
            return false;
    }
    return true;
}
};
