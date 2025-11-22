#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100;
vector<int> adj[MAXN];     
bool visited[MAXN];        
int n;                     

int BFS_with_path(int source, int target) {
    queue<int> q;
    int dist[MAXN];        // distance 

    for (int i = 0; i < n; i++) {
        visited[i] = false;
        dist[i] = -1;
    }

    visited[source] = true;
    dist[source] = 0;
    q.push(source);

    // BFS
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        if (v == target) return dist[v];

        for (int i = 0 ; i< adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = true;
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }

    
        return -1 ;
}

int main() {
    int x;
    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        for (int j = 0; j < n; j++) {
            cin >> x;
            if (x == 1) {
                adj[i].push_back(j);
            }
        }
    }

    int a, b;
    cin >> a >> b;
    a--;
    b--;
    int ans = BFS_with_path(a, b);
    cout << ans << endl ;
    return 0;
}
