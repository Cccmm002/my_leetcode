// Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.
//
//
//
//
// OJ's undirected graph serialization:
//
//
// Nodes are labeled uniquely.
//
//
// We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
//
//
//
//
// As an example, consider the serialized graph {0,1,2#1,2#2,2}.
//
//
//
// The graph has a total of three nodes, and therefore contains three parts as separated by #.
//
// First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
// Second node is labeled as 1. Connect node 1 to node 2.
// Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
//
//
//
//
// Visually, the graph looks like the following:
//
//        1
//       / \
//      /   \
//     0 --- 2
//          / \
//          \_/


/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
 
typedef UndirectedGraphNode *pNode;
 
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node==NULL) return NULL;
        
        queue<pNode> q;
        q.push(node);
        map<int, pNode> nodeList;
        nodeList[node->label]=node;
        
        while(!q.empty()){
            pNode pn=q.front();
            q.pop();
            for(int i=0;i<pn->neighbors.size();i++){
                pNode n=pn->neighbors[i];
                if(nodeList.find(n->label)!=nodeList.end())
                    continue;
                nodeList[n->label]=n;
                q.push(n);
            }
        }
        
        map<int, pNode> newNodeList;
        map<int, pNode>::iterator it=nodeList.begin();
        while(it!=nodeList.end()){
            newNodeList[it->first]=new UndirectedGraphNode(it->first);
            it++;
        }
        
        it=nodeList.begin();
        while(it!=nodeList.end()){
            vector<pNode> v=it->second->neighbors;
            for(int i=0;i<v.size();i++)
                newNodeList[it->first]->neighbors.push_back(newNodeList[v[i]->label]);
            it++;
        }
        return newNodeList[node->label];
    }
};
