class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;

        for(int i=0; i<=k; i++) {
            vector<int> tmp = dist;

            for(int j=0; j<flights.size(); j++) {
                int from = flights[j][0];
                int to = flights[j][1];
                int price = flights[j][2];

                if(dist[from] != INT_MAX && tmp[to] > dist[from] + price) {
                    tmp[to] = dist[from] + price;
                }
            }

            dist = tmp;
        }

        if(dist[dst] == INT_MAX) {
            return -1;
        }
        return dist[dst];
    }
};