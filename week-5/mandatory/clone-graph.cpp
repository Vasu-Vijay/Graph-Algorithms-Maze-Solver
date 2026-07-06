/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/
Node* dfs(Node* node, unordered_set<Node*>& visited, unordered_map<Node*, Node*>& mapping) {
    if(!node) { return NULL; }
    if(visited.count(node)) { return NULL; } 
    visited.insert(node);

    Node* root = new Node(node->val);

    mapping.insert({node, root});

    vector<Node*>& neighbors = node->neighbors;
    for(auto x: neighbors) {
        dfs(x, visited, mapping);
        root->neighbors.push_back(mapping[x]);
    }

    return root;
}

class Solution {
public:
    Node* cloneGraph(Node* node) {
        unordered_set<Node*> visited;
        unordered_map<Node*, Node*> mapping;
        return dfs(node, visited, mapping);
    }
};