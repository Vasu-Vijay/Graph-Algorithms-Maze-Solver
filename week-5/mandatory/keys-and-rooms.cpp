class Solution {
private:

    void dfs(vector<vector<int>>& rooms, vector<bool>& visited, int i) {
        if(visited[i]) { return; }
        visited[i] = true;
        
        for(int j: rooms[i]) {
            dfs(rooms, visited, j);
        }
        return;
    }

public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited (n, false);
        dfs(rooms, visited, 0);
        for(bool b: visited) {
            if(!b) 
                return false;
        }
        return true;
    }
};