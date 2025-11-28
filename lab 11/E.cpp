#include <bits/stdc++.h>
using namespace std ;
struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]); // path compression
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;          // already in same set
        if (rank[a] < rank[b]) swap(a, b); // union by rank
        parent[b] = a;
        if (rank[a] == rank[b]) rank[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    if (!(cin >> n >> m)) return 0;

    vector<vector<int>> adj(n);
    for (int i = 0; i < m; ++i) {
        int u, v;
        cin >> u >> v;
        --u; --v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    DSU dsu(n);
    vector<int> active(n, 0);
    vector<int> ans(n, 0);

    int components = 0;

    for (int i = n - 1; i >= 0; --i) {
        active[i] = 1;
        components++;

        for (int v : adj[i]) {
            if (active[v]) {
                if (dsu.unite(i, v)) {
                    components--;
                }
            }
        }

        ans[i] = components;
    }

   
    for (int k = 1; k < n; ++k) {
        cout << ans[k] << endl;
    }
    cout << 0 << endl;

    return 0;
}
