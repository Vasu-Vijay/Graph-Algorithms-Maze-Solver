class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        queue<int> q;
        vector<int> distances(n, -1);
        int dist;
        for(int i=0; i<n; i++) {
            if(distances[i] != -1) {
                continue;
            } else {
                q.push(i);
                q.push(-1);
                int front;
                distances[i] = 0;
                dist=1;
                while(q.size() > 1) {
                    front = q.front();
                    q.pop();
                    if(front == -1) {
                        q.push(-1);
                        dist++;
                        continue;
                    }
                    for(int j: graph[front]) {
                        if(distances[j] == -1) {
                            q.push(j);
                            distances[j] = dist;
                        } else {
                            if((distances[j] + dist)%2==1) {
                                return false;
                            }
                        }
                    }
                }
                q.pop();
                dist=0;
            }
        }
        return true;
    }
};