class Solution {
public:
    int dfs(vector<vector<char>>& grid, vector<vector<int>>& visited, int m, int n, int i, int j) {
        if(i<0 || i>=m || j<0 || j>=n) { return 0; }
        if(grid[i][j] == '0') { return 0; }
        if(visited[i][j]) { return 0; }

        visited[i][j] = 1;

        dfs(grid, visited, m, n, i+1, j);
        dfs(grid, visited, m, n, i-1, j);
        dfs(grid, visited, m, n, i, j+1);
        dfs(grid, visited, m, n, i, j-1);
        
        return 1;
    }

    int numIslands(vector<vector<char>>& grid) {
        int count = 0; 
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> visited(m, vector<int> (n,0));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                count += dfs(grid, visited, m, n, i, j);
            }
        }

        return count;
    }
};