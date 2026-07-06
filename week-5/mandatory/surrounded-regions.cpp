bool dfs(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
    int m = board.size(), n = board[0].size();
    if(i<0 || i>=m || j<0 || j>=n) { return false; } 
    if(board[i][j] == 'X') { return true; }
    if(visited[i][j]) { return true; }
    visited[i][j] = true;
    bool surrounded = dfs(board, visited, i+1, j) && dfs(board, visited, i-1, j) && dfs(board, visited, i, j+1) && dfs(board, visited, i, j-1);
    if(surrounded) {
        board[i][j] = 'X';
    }
    return surrounded;
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                dfs(board, visited, i, j);
            }
        }
    }
};