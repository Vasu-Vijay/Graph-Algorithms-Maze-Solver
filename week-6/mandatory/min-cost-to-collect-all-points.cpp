class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        vector<int> dist(n, INT_MAX);
        vector<bool> visited(n, false);

        dist[0] = 0;
        int ans = 0;

        for(int i=0; i<n; i++) {
            int curr = -1;

            for(int j=0; j<n; j++) {
                if(!visited[j] && (curr == -1 || dist[j] < dist[curr])) {
                    curr = j;
                }
            }

            visited[curr] = true;
            ans += dist[curr];

            for(int j=0; j<n; j++) {
                if(!visited[j]) {
                    int cost = abs(points[curr][0] - points[j][0]) + abs(points[curr][1] - points[j][1]);
                    if(cost < dist[j]) {
                        dist[j] = cost;
                    }
                }
            }
        }

        return ans;
    }
};