class Solution {
private:
    void handle(vector<vector<int>>& mat, queue<pair<int,int>>& q, vector<vector<int>>& ans, int i, int j, int dist) {
        int m = mat.size(), n = mat[0].size();
        if(i<0 || i>=m || j<0 || j>=n) {
            return;
        }
        if(mat[i][j] == 0) { return; }
        if(ans[i][j] > 0 ) { return; }
        ans[i][j] = dist;
        q.push({i, j});
    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> ans(m, vector<int>(n, 0));

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(mat[i][j] == 0)
                    q.push({i, j});
            }
        }

        int dist = 1;
        while(!q.empty()) {
            int sz = q.size();
            while(sz--) {
                auto [i, j] = q.front();
                q.pop();

                handle(mat, q, ans, i+1, j, dist);
                handle(mat, q, ans, i-1, j, dist);
                handle(mat, q, ans, i, j+1, dist);
                handle(mat, q, ans, i, j-1, dist);
            }
            dist++;
        }
        return ans;
    }
};