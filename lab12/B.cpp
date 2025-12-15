#include <bits/stdc++.h>
using namespace std ;

const int INF = 1000000000;


vector<long long> dijkstra(int n, int src, vector<vector<pair<int,int>>> &adj) {
    vector<long long> dist(n+1, INF);
    dist[src] = 0;
    priority_queue<pair<long long,int>, vector<pair<long long,int>>, greater<>> pq;
    pq.push({0, src});
    while (!pq.empty()) {
        auto [d,u] = pq.top(); pq.pop();
        if (d > dist[u]) continue;
        for (auto [v,w] : adj[u]) {
            if (dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                pq.push({dist[v], v});
            }
        }
    }
    return dist;
}

int main(){
    ios:: sync_with_stdio(false);
    cin.tie(NULL);
    
    int N, M; 
    cin >> N >> M;
    vector<vector<pair<int,int> > > adj(N+1);
    for (int i=0; i<M; i++) {
        int u,v,c; cin >> u >> v >> c;
        adj[u].push_back({v,c});
        adj[v].push_back({u,c}); 
    }

    int s,a,b,f; 
    cin >> s >> a >> b >> f;

    auto distS = dijkstra(N, s, adj);
    auto distA = dijkstra(N, a, adj);
    auto distB = dijkstra(N, b, adj);
    long long route1 = distS[a] + distA[b] + distB[f];
    long long route2 = distS[b] + distB[a] + distA[f];
    long long ans = min(route1, route2);

    if (ans >= INF) cout << -1 << endl;
    else cout << ans << endl;

    return 0; 
}