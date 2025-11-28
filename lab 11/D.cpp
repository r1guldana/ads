#include <bits/stdc++.h>
using namespace std;
struct Edge {
    int u, v;
    long long w ;
    bool operator<(const Edge& other) const { return w < other.w; }
};
struct DSU {
    vector<int> parent, rnk;
    DSU(int n) : parent(n), rnk(n, 0) {
        for (int i = 0; i < n; i++) parent[i] = i;
    }
    int find(int v) {
        if (parent[v] == v) return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a, int b) {
        a = find(a); b = find(b);
        if (a == b) return false;
        if (rnk[a] < rnk[b]) swap(a, b);
        parent[b] = a;
        if (rnk[a] == rnk[b]) rnk[a]++;
        return true;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;
    vector<Edge> edges;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int val;
            cin >> val;
            if (i < j) { 
                Edge e;
                e.u = i;
                e.v = j;
                e.w = val;
                edges.push_back(e);
            }
        }
    }

    sort(edges.begin(), edges.end());

    DSU dsu(n);
    long long cost = 0;
    int cnt = 0;

    for (size_t i = 0; i < edges.size() && cnt < n-1; i++) {
        if (dsu.unite(edges[i].u, edges[i].v)) {
            cost += edges[i].w;
            cnt++;
        }
    }

    cout << cost << endl;
    return 0;
}
