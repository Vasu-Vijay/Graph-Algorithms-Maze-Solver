class Solution {
private:
    bool handle(vector<vector<int>>& grid, queue<pair<int, int>>& q, int i, int j) {
        int m = grid.size(), n = grid[0].size();
        if (i < 0 || i >= m || j < 0 || j >= n) {
            return false;
        }
        if(grid[i][j] == 2 || grid[i][j]==0) { 
            return false;
        }
        grid[i][j] = 2;
        q.push({i,j});
        return true;
    }

public:
    int orangesRotting(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 2)
                    q.push({i, j});
            }
        }
        int time = 0;
        while(!q.empty()) {
            int sz = q.size();
            bool rotted = false;
            while (sz--) {
                auto [i, j] = q.front();
                q.pop();

                rotted = handle(grid, q, i+1, j) || rotted;
                rotted = handle(grid, q, i-1, j) || rotted;
                rotted = handle(grid, q, i, j+1) || rotted;
                rotted = handle(grid, q, i, j-1) || rotted;
            }
            if(rotted) { time++; }
        }

        for(int i=0; i<m ; i++) {
            for(int j=0; j<n; j++) {
                if(grid[i][j] == 1) {
                    return -1;
                }
            }
        }

        return time;
    }
};