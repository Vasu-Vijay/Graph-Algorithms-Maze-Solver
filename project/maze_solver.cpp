#include <bits/stdc++.h>
using namespace std;

struct Grid {
    int R, C;
    vector<string> cells;
};

struct Result {
    int cost;
    vector<pair<int, int>> path;
    int expanded;
};

vector<pair<int, int>> neighbours(const Grid &g, int r, int c) {
    vector<pair<int, int>> ans;
    int dr[4] = {0, 0, 1, -1};
    int dc[4] = {1, -1, 0, 0};
    for (int i = 0; i < 4; i++) {
        int nr = r + dr[i];
        int nc = c + dc[i];
        if (nr >= 0 && nr < g.R && nc >= 0 && nc < g.C &&
            g.cells[nr][nc] != '#') {
            ans.push_back({nr, nc});
        }
    }
    return ans;
}

vector<pair<int, int>> makepath(pair<int, int> s, pair<int, int> t, vector<vector<pair<int, int>>> &parent) {
    vector<pair<int, int>> path;
    if (parent[t.first][t.second].first == -1 && s != t) {
        return path;
    }
    pair<int, int> curr = t;
    while (curr != s) {
        path.push_back(curr);
        curr = parent[curr.first][curr.second];
    }
    path.push_back(s);
    reverse(path.begin(), path.end());
    return path;
}

Result bfs(const Grid &g, pair<int, int> s, pair<int, int> t) {
    vector<vector<int>> dist(g.R, vector<int>(g.C, -1));
    vector<vector<pair<int, int>>> parent(g.R, vector<pair<int, int>>(g.C, {-1, -1}));
    queue<pair<int, int>> q;
    q.push(s);
    dist[s.first][s.second] = 0;
    int expanded = 0;

    while (!q.empty()) {
        pair<int, int> curr = q.front();
        q.pop();
        expanded++;
        if (curr == t) {
            break;
        }
        vector<pair<int, int>> nexts = neighbours(g, curr.first, curr.second);
        for (int i = 0; i < nexts.size(); i++) {
            int r = nexts[i].first;
            int c = nexts[i].second;
            if (dist[r][c] == -1) {
                dist[r][c] = dist[curr.first][curr.second] + 1;
                parent[r][c] = curr;
                q.push({r, c});
            }
        }
    }
    return {dist[t.first][t.second], makepath(s, t, parent), expanded};
}

Result dfsPath(const Grid &g, pair<int, int> s, pair<int, int> t) {
    vector<vector<bool>> visited(g.R, vector<bool>(g.C, false));
    vector<vector<pair<int, int>>> parent(g.R, vector<pair<int, int>>(g.C, {-1, -1}));
    stack<pair<int, int>> st;
    st.push(s);
    visited[s.first][s.second] = true;
    int expanded = 0;

    while (!st.empty()) {
        pair<int, int> curr = st.top();
        st.pop();
        expanded++;
        if (curr == t) {
            break;
        }
        vector<pair<int, int>> nexts = neighbours(g, curr.first, curr.second);
        for (int i = 0; i < nexts.size(); i++) {
            int r = nexts[i].first;
            int c = nexts[i].second;
            if (!visited[r][c]) {
                visited[r][c] = true;
                parent[r][c] = curr;
                st.push({r, c});
            }
        }
    }
    vector<pair<int, int>> path = makepath(s, t, parent);
    int cost = path.empty() ? -1 : path.size() - 1;
    return {cost, path, expanded};
}

int terraincost(char ch) {
    if (ch >= '0' && ch <= '9') {
        return ch - '0';
    }
    return 1;
}

int movecost(const Grid &g, pair<int, int> a, pair<int, int> b) {
    return max(terraincost(g.cells[a.first][a.second]), terraincost(g.cells[b.first][b.second]));
}

Result dijkstra(const Grid &g, pair<int, int> s, pair<int, int> t) {
    vector<vector<int>> dist(g.R, vector<int>(g.C, INT_MAX));
    vector<vector<pair<int, int>>> parent(g.R, vector<pair<int, int>>(g.C, {-1, -1}));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[s.first][s.second] = 0;
    pq.push({0, s});
    int expanded = 0;

    while (!pq.empty()) {
        int cost = pq.top().first;
        pair<int, int> curr = pq.top().second;
        pq.pop();
        if (cost != dist[curr.first][curr.second]) {
            continue;
        }
        expanded++;
        if (curr == t) {
            break;
        }
        vector<pair<int, int>> nexts = neighbours(g, curr.first, curr.second);
        for (int i = 0; i < nexts.size(); i++) {
            pair<int, int> next = nexts[i];
            int newcost = cost + movecost(g, curr, next);
            if (newcost < dist[next.first][next.second]) {
                dist[next.first][next.second] = newcost;
                parent[next.first][next.second] = curr;
                pq.push({newcost, next});
            }
        }
    }
    int cost = dist[t.first][t.second] == INT_MAX ? -1 : dist[t.first][t.second];
    return {cost, makepath(s, t, parent), expanded};
}

Result astar(const Grid &g, pair<int, int> s, pair<int, int> t) {
    vector<vector<int>> dist(g.R, vector<int>(g.C, INT_MAX));
    vector<vector<pair<int, int>>> parent(g.R, vector<pair<int, int>>(g.C, {-1, -1}));
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
    dist[s.first][s.second] = 0;
    pq.push({abs(s.first - t.first) + abs(s.second - t.second), s});
    int expanded = 0;

    while (!pq.empty()) {
        pair<int, int> curr = pq.top().second;
        int heuristic = abs(curr.first - t.first) + abs(curr.second - t.second);
        int cost = pq.top().first - heuristic;
        pq.pop();
        if (cost != dist[curr.first][curr.second]) {
            continue;
        }
        expanded++;
        if (curr == t) {
            break;
        }
        vector<pair<int, int>> nexts = neighbours(g, curr.first, curr.second);
        for (int i = 0; i < nexts.size(); i++) {
            pair<int, int> next = nexts[i];
            int newcost = cost + movecost(g, curr, next);
            if (newcost < dist[next.first][next.second]) {
                dist[next.first][next.second] = newcost;
                parent[next.first][next.second] = curr;
                int h = abs(next.first - t.first) + abs(next.second - t.second);
                pq.push({newcost + h, next});
            }
        }
    }
    int cost =
        dist[t.first][t.second] == INT_MAX ? -1 : dist[t.first][t.second];
    return {cost, makepath(s, t, parent), expanded};
}

int tried;
void orderdfs(const vector<vector<int>> &dist, int curr, int goalIdx, vector<bool> &used, vector<int> &order, vector<int> &best, int cost, int &ans) {
    if (cost >= ans) {
        return;
    }
    bool done = true;
    for (int i = 1; i < goalIdx; i++) {
        if (!used[i]) {
            done = false;
            break;
        }
    }
    if (done) {
        tried++;
        cost += dist[curr][goalIdx];
        if (cost < ans) {
            ans = cost;
            best = order;
        }
        return;
    }
    for (int i = 1; i < goalIdx; i++) {
        if (!used[i]) {
            used[i] = true;
            order.push_back(i);
            orderdfs(dist, i, goalIdx, used, order, best, cost + dist[curr][i],
                     ans);
            order.pop_back();
            used[i] = false;
        }
    }
}

int bestOrder(const vector<vector<int>> &dist, int startIdx, int goalIdx, vector<int> &outOrder) {
    vector<bool> used(goalIdx + 1, false);
    vector<int> order, best;
    int ans = INT_MAX;
    tried = 0;
    orderdfs(dist, startIdx, goalIdx, used, order, best, 0, ans);
    outOrder = best;
    return ans;
}

string ordertext(const vector<int> &order, const vector<pair<int, int>> &points) {
    string ans = "S";
    for (int i = 0; i < order.size(); i++) {
        pair<int, int> p = points[order[i]];
        ans += " -> c(" + to_string(p.first) + "," + to_string(p.second) + ")";
    }
    return ans + " -> G";
}

vector<string> drawpath(const Grid &g, const vector<int> &order, const vector<pair<int, int>> &points, const vector<vector<Result>> &paths) {
    vector<string> ans = g.cells;
    int curr = 0;
    vector<int> route = order;
    route.push_back(points.size() - 1);
    for (int i = 0; i < route.size(); i++) {
        vector<pair<int, int>> path = paths[curr][route[i]].path;
        for (int j = 0; j < path.size(); j++) {
            int r = path[j].first;
            int c = path[j].second;
            if (ans[r][c] == '.') {
                ans[r][c] = '*';
            }
        }
        curr = route[i];
    }
    return ans;
}

int main(int argc, char *argv[]) {
    ifstream fin(argv[1]);
    Grid g;
    pair<int, int> start, goal;
    fin >> g.R >> g.C >> start.first >> start.second >> goal.first >> goal.second;
    g.cells.resize(g.R);
    for (int i = 0; i < g.R; i++) {
        fin >> g.cells[i];
    }

    vector<pair<int, int>> points;
    points.push_back(start);
    for (int i = 0; i < g.R; i++) {
        for (int j = 0; j < g.C; j++) {
            if (g.cells[i][j] == 'c') {
                points.push_back({i, j});
            }
        }
    }
    points.push_back(goal);
    int sz = points.size();
    vector<vector<int>> bfsdist(sz, vector<int>(sz));
    vector<vector<int>> dijdist(sz, vector<int>(sz));
    vector<vector<Result>> bfspaths(sz, vector<Result>(sz));
    vector<vector<Result>> dijpaths(sz, vector<Result>(sz));
    int dijexpanded = 0, astarexpanded = 0;

    Result dfsdemo = dfsPath(g, start, goal);
    (void)dfsdemo;
    for (int i = 0; i < sz; i++) {
        for (int j = 0; j < sz; j++) {
            Result b = bfs(g, points[i], points[j]);
            Result d = dijkstra(g, points[i], points[j]);
            Result a = astar(g, points[i], points[j]);
            if (b.cost == -1 || d.cost == -1 || a.cost != d.cost) {
                cout << "Path found: no" << endl;
                return 0;
            }
            bfsdist[i][j] = b.cost;
            dijdist[i][j] = d.cost;
            bfspaths[i][j] = b;
            dijpaths[i][j] = d;
            dijexpanded += d.expanded;
            astarexpanded += a.expanded;
        }
    }

    vector<int> bfsorder, dijorder;
    int bfsbest = bestOrder(bfsdist, 0, sz - 1, bfsorder);
    int bfsorders = tried;
    int dijbest = bestOrder(dijdist, 0, sz - 1, dijorder);
    int dijorders = tried;

    cout << "=== UNIFORM COST (BFS + DFS) ===" << endl;
    cout << "Coins: " << sz - 2 << endl;
    cout << "Best order: " << ordertext(bfsorder, points) << endl;
    cout << "Total steps: " << bfsbest << endl;
    cout << "Path:" << endl;
    vector<string> uniformpath = drawpath(g, bfsorder, points, bfspaths);
    for (int i = 0; i < g.R; i++) {
        cout << uniformpath[i] << endl;
    }
    cout << endl;
    cout << "=== WEIGHTED (Dijkstra + A*) ===" << endl;
    cout << "Coins: " << sz - 2 << endl;
    cout << "Best order: " << ordertext(dijorder, points) << endl;
    cout << "Total cost: " << dijbest << endl;
    cout << "A* cells expanded across all pair queries: " << astarexpanded << endl;
    cout << "Dijkstra cells expanded across all pair queries: " << dijexpanded << endl << endl;
    cout << "[SUMMARY]: BFS pairs computed: " << sz * sz << " | DFS orderings tried: " << dijorders << " | Dijkstra: " << dijexpanded << " | A*: " << astarexpanded << endl;
}
