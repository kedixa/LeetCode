/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
    using Node = UndirectedGraphNode;
    unordered_map<Node*, Node*> mp; // 旧的点到新的点的映射
    void build(Node* node)
    {
        if(mp.find(node) == mp.end())
            mp[node] = new Node(node->label);
        Node *p = mp[node];
        p->neighbors.reserve(node->neighbors.size());
        for(auto &q : node->neighbors)
        {
            if(mp.find(q) == mp.end())
                build(q);
            p->neighbors.push_back(mp[q]);
        }
    }
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        // 不使用递归可能会更快
        mp.clear();
        if(node == nullptr) return nullptr;
        build(node);
        return mp[node];
    }
};
