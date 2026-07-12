void handle(vector<vector<int>>& grid, queue<int>& qi, queue<int>& qj, vector<vector<int>>& secs, int i, int j, int parent_sec, vector<vector<bool>>& visited) {
    int m = grid.size(), n = grid[0].size();
    if (i < 0 || i >= m || j < 0 || j >= n) {
        return;
    }
    if(visited[i][j]) { return; }
    if(grid[i][j] == 2 || grid[i][j] == 0) {
        return;
    }
    visited[i][j] = true;
    grid[i][j] = 3;
    secs[i][j] = min(secs[i][j],parent_sec + 1);
    qi.push(i);
    qj.push(j);
    return;
}

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<int> qi, qj;
        int fi, fj;
        vector<vector<int>> secs(m, vector<int>(n, INT_MAX));

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2) {
                    vector<vector<bool>> visited(m, vector<bool>(n, false));
                    visited[i][j] = true;
                    secs[i][j] = 0;
                    qi.push(i);
                    qj.push(j);
                    while (!qi.empty() && !qj.empty()) {
                        fi = qi.front();
                        fj = qj.front();
                        qi.pop();
                        qj.pop();

                        handle(grid, qi, qj, secs, fi+1, fj, secs[fi][fj], visited);
                        handle(grid, qi, qj, secs, fi-1, fj, secs[fi][fj], visited);
                        handle(grid, qi, qj, secs, fi, fj+1, secs[fi][fj], visited);
                        handle(grid, qi, qj, secs, fi, fj-1, secs[fi][fj], visited);
                    }
                }
            }
        }
        for(int i=0; i<m ; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }
        
        int ans = 0;
        for(int i=0; i<m ; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 3) {
                    ans = max(ans, secs[i][j]);
                }
            }
        }
        return ans;
    }
};