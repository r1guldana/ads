#include <bits/stdc++.h>
using namespace std ;

const int MAXN = 100000;
vector<int> adj[MAXN];
bool visited[MAXN];
int n, m;
bool BFS(int source, int target) {
    queue<int> q;

    fill(visited, visited + n + 1, false);

    visited[source] = true;
    q.push(source);


    while (!q.empty()) {
        int v = q.front();
        q.pop();

        if(v == target) return true;

        for (int i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            if (!visited[u]) {
                visited[u] = true;
                q.push(u);
            }
        }
    }

    return false;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m;
    for (int i = 0; i < m; i++) {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }
    int s, f;
    cin>> s>> f ;
    if(BFS(s, f)) cout << "YES"<<endl ;
    else cout << "NO"<<endl ;
}
