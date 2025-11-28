#include <bits/stdc++.h>
using namespace std;

struct DSU {
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0) {
        iota(parent.begin(), parent.end(), 0);
    }
    
    int find(int x) {
        return parent[x] == x ? x : parent[x] = find(parent[x]);
    }
    
    bool unite(int x, int y) {
        x = find(x);
        y = find(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y);
        parent[y] = x;
        if (rank[x] == rank[y]) rank[x]++;
        return true;
    }
};

struct Edge {
    int l, r;
    long long w;
    bool operator<(const Edge& other) const {
        return w < other.w;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, m;
    cin >> n >> m;
    
    vector<Edge> edges(m);
    for (int i = 0; i < m; i++) {
        cin >> edges[i].l >> edges[i].r >> edges[i].w;
        edges[i].l--;
        edges[i].r--;
    }
    
    sort(edges.begin(), edges.end());
    
    DSU dsu(n);
    vector<int> nxt(n);
    iota(nxt.begin(), nxt.end(), 0);
    
    long long total = 0;
    int edges_used = 0;
    
    for (const Edge& e : edges) {
        if (edges_used == n - 1) break;
        
        int current = e.l;
        while (current < e.r) {
          
            if (nxt[current] != current) {
                int temp = nxt[current];
                nxt[current] = nxt[temp];
                current = temp;
            }
            if (current >= e.r) break;
            
            if (dsu.unite(current, current + 1)) {
                total += e.w;
                edges_used++;
            }
            nxt[current] = current + 1;
            current++;
        }
    }
    
    cout << total << "\n";
    
    return 0;
}