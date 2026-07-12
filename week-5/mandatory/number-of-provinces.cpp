void dfs(vector<vector<int>>& isConnected, vector<bool>& visited, int i) {
    int n = isConnected.size();
    if(i<0 || i>=n) { return; }
    if(visited[i]) { return; }

    visited[i] = true;
    for(int j=0; j<n; j++) {
        if(isConnected[i][j]) {
            dfs(isConnected, visited, j);
        }
    }
}

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int count = 0;
        vector<bool> visited(n, false);
        for(int i=0; i<n; i++) {
            if(!visited[i]) {
                count++;
                dfs(isConnected, visited, i);
            }
        }
        return count;
    }
};