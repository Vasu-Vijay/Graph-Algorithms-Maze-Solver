bool checkSurrounded(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
    int m = board.size(), n = board[0].size();
    if(i<0 || i>=m || j<0 || j>=n) { return false; }
    if(board[i][j] == 'X') { return true; } 
    if(visited[i][j]) { return true; }

    visited[i][j] = true;
    bool surrounded = checkSurrounded(board, visited, i+1, j) && checkSurrounded(board, visited, i-1, j) && checkSurrounded(board, visited, i, j+1) && checkSurrounded(board, visited, i, j-1);
    // visited[i][j]=false;
    if(surrounded)
    return surrounded;
}

void convert(vector<vector<char>>& board, vector<vector<bool>>& visited, int i, int j) {
    // cout<<"convert called for i="<<i<<", j="<<j<<endl;
    int m = board.size(), n = board[0].size();
    if(i<0 || i>=m || j<0 || j>=n) { return; }
    if(board[i][j] == 'X') { return; }

    board[i][j]='X';
    convert(board, visited, i+1, j);
    convert(board, visited, i-1, j);
    convert(board, visited, i, j+1);
    convert(board, visited, i, j-1);
}

class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        for(int i=0; i<m; i++) {
            for(int j=0; j<n; j++) {
                if((!visited[i][j]) && board[i][j]=='O' && checkSurrounded(board, visited, i, j)) {
                    convert(board,visited, i,j);
                }
            }
        }
    }
};