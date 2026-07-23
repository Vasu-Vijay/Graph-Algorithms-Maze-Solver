class Solution {
public:
    bool checkcycle(int curr, vector<vector<int>>& adj, vector<int>& visited) {
        if(visited[curr] == 1) {
            return true;
        }
        if(visited[curr] == 2) {
            return false;
        }

        visited[curr] = 1;
        for(int i=0; i<adj[curr].size(); i++) {
            if(checkcycle(adj[curr][i], adj, visited)) {
                return true;
            }
        }
        visited[curr] = 2;
        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        for(int i=0; i<prerequisites.size(); i++) {
            int course = prerequisites[i][0];
            int prereq = prerequisites[i][1];
            adj[course].push_back(prereq);
        }

        vector<int> visited(numCourses, 0);
        for(int i=0; i<numCourses; i++) {
            if(visited[i] == 0 && checkcycle(i, adj, visited)) {
                return false;
            }
        }
        return true;
    }
};