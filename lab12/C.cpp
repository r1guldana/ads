#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > adj(n + 1);
    vector<vector<char> > has(n + 1, vector<char>(n + 1, false));

    for (int i = 0; i < m; i++) {
        int u, v; 
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
        has[u][v] = has[v][u] = true;
    }

    auto bfs = [&](bool useComplement) -> int {
        vector<int> dist(n + 1, -1);
        queue<int> q;
        dist[1] = 0;
        q.push(1);

        while (!q.empty()) {
            int u = q.front(); q.pop();

            if (!useComplement) {
                for (int v : adj[u]) {
                    if (dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            } else {
                for (int v = 1; v <= n; v++) {
                    if (v == u) continue;
                    if (!has[u][v] && dist[v] == -1) {
                        dist[v] = dist[u] + 1;
                        q.push(v);
                    }
                }
            }
        }
        return dist[n];
    };

    bool edge_1 = has[1][n];

    int ans = bfs(edge_1); 
    cout << ans << endl ;
    return 0;
}
