class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adj(n+1);
        for(int i=0; i<times.size(); i++) {
            int from = times[i][0];
            int to = times[i][1];
            int time = times[i][2];
            adj[from].push_back({to, time});
        }

        vector<int> dist(n+1, INT_MAX);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[k] = 0;
        pq.push({0, k});

        while(!pq.empty()) {
            int currtime = pq.top().first;
            int curr = pq.top().second;
            pq.pop();

            if(currtime > dist[curr]) {
                continue;
            }

            for(int i=0; i<adj[curr].size(); i++) {
                int next = adj[curr][i].first;
                int time = adj[curr][i].second;

                if(dist[next] > currtime + time) {
                    dist[next] = currtime + time;
                    pq.push({dist[next], next});
                }
            }
        }

        int ans = 0;
        for(int i=1; i<=n; i++) {
            if(dist[i] == INT_MAX) {
                return -1;
            }
            ans = max(ans, dist[i]);
        }
        return ans;
    }
};