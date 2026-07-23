class Solution {
public:
    int findparent(int node, vector<int>& parent) {
        if(parent[node] == node) {
            return node;
        }
        return parent[node] = findparent(parent[node], parent);
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1);

        for(int i=1; i<=n; i++) {
            parent[i] = i;
        }

        for(int i=0; i<edges.size(); i++) {
            int u = edges[i][0];
            int v = edges[i][1];

            int parentu = findparent(u, parent);
            int parentv = findparent(v, parent);

            if(parentu == parentv) {
                return edges[i];
            }

            parent[parentu] = parentv;
        }

        return {};
    }
};