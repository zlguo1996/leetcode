/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cG(UndirectedGraphNode *node, map<int, UndirectedGraphNode*>& node_map){
        if(!node) return NULL;
        
        int label = node->label;
        if(node_map.count(label)==1) return node_map.find(label)->second;
        
        UndirectedGraphNode* cur_node = new UndirectedGraphNode(label);
        node_map[label] = cur_node;
        for(auto n:node->neighbors) cur_node->neighbors.push_back(cG(n, node_map));
        return cur_node;
    }
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        map<int, UndirectedGraphNode*> node_map;
        return cG(node, node_map);
    }
};
