#include <bits/stdc++.h>
using namespace std;

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

struct Edge {
    int u, v;
    long long w ;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin>>n;
    vector<long long> d(n);
    for (int i = 0; i < n; i++)
    {
        cin>> d[i];
    }
    
    vector<Edge>edges;
    for (int i = 0; i < n; i++) {
    for (int j = i+1; j < n; j++) {
        Edge e;
        e.u = i;
        e.v = j;
        e.w = d[i] + d[j];
        edges.push_back(e);
    }
}
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long cost = 0;
    int cnt = 0;
    for (size_t i = 0; i < edges.size() && cnt<n-1; i++)
    {
        if(dsu.unite(edges[i].u, edges[i].v)){
            cost += edges[i].w ;
            cnt++;
        }
    }
    cout << cost<<endl;
return 0;
}