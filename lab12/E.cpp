#include <bits/stdc++.h>
using namespace std;

const long long INF = 1e9;

struct Edge {
    int u, v;
    long long w;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            long long w;
            cin >> w;
            if (w != 100000) {
                edges.push_back({i, j, w});
            }
        }
    }

    vector<long long> dist(n, 0);
    vector<int> parent(n, -1);
    int x = -1;

    for (int i = 0; i < n; i++) {
        x = -1;
        for (auto &e : edges) {
            if (dist[e.u] + e.w < dist[e.v]) {
                dist[e.v] = max(-INF, dist[e.u] + e.w);
                parent[e.v] = e.u;
                x = e.v;
            }
        }
    }

    if (x == -1) {
        cout << "NO"<<endl;
    } else {
        cout << "YES"<< endl;
        int y = x;
        for (int i = 0; i < n; i++) y = parent[y];

        vector<int> cycle;
        for (int cur = y;; cur = parent[cur]) {
            cycle.push_back(cur);
            if (cur == y && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());

        cout << cycle.size() << endl;
        for (int v : cycle) cout << v+1 << " "; 
        cout << endl;
    }
}
