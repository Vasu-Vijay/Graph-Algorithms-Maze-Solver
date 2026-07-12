class Solution {
private:
    void DFS(vector<vector<int>>& heights, vector<vector<int>>& visited, int i, int j, int mask) {
        int m = heights.size(), n = heights[0].size();
        if(i<0 || i>=m || j<0 || j>=n) {
            return;
        }
        if(visited[i][j] == mask || visited[i][j] == 3) {
            return;
        } 
        visited[i][j] += mask;

        if(i<m-1 && heights[i][j] <= heights[i+1][j])
            DFS(heights, visited, i+1, j, mask);
        if(i>0 && heights[i][j] <= heights[i-1][j])
            DFS(heights, visited, i-1, j, mask);  

        if(j<n-1 && heights[i][j] <= heights[i][j+1])
            DFS(heights, visited, i, j+1, mask);
        if(j>0 && heights[i][j] <= heights[i][j-1])
            DFS(heights, visited, i, j-1, mask);

        return;
    }

public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int m = heights.size(), n = heights[0].size();
        vector<vector<int>> visited (m, vector<int> (n, 0));
        vector<vector<int>> ans;

        for(int i=0; i<m; i++) {
            DFS(heights, visited, i, 0, 1);
        }
        for(int j=0; j<n; j++) {
            DFS(heights, visited, 0, j, 1);
        }

        for(int i=0; i<m; i++) {
            DFS(heights, visited, i, n-1, 2);
        }
        for(int j=0; j<n; j++) {
            DFS(heights, visited, m-1, j, 2);
        }

        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if(visited[i][j] == 3) {
                    ans.push_back({i, j});
                }
            }
        }

        return ans;
    }
};