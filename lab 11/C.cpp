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

struct Edge {
    int u, v;
    long long w ;
    bool operator<(const Edge& other) const { return w < other.w; }
};

int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin>> n>>m;
    long long x, y;
    cin >> x >> y;
    vector<Edge> edges;
    edges.reserve(m);
    for (int i = 0; i < m; i++)
    {
        string type;
        int a, b;
        long long c;
        cin>>type>>a>>b>>c;
        long long km ;
        if(type == "big") km = x ;
        else if(type=="small") km = y ;
        else km = (x<y ? x : y);  //"both";
        Edge e;
        e.u = a - 1;  // 0
        e.v = b - 1;
        e.w = km * c;
        edges.push_back(e);
    }
    if(n==1) cout << 0 <<endl ;
    sort(edges.begin(), edges.end());
    DSU dsu(n);
    long long total = 0;
    int taken = 0;    
    for (size_t i = 0; i < edges.size() && taken <n-1; i++)
    {
        if(dsu.unite(edges[i].u, edges[i].v)){
            total+= edges[i].w ;
            taken++ ;
        }
    }
    cout << total << endl;
    return 0;
}