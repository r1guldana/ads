#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector< vector<int> > adj(n+1);
    vector<int> indegree(n+1, 0);

    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        indegree[v]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (indegree[i] == 0) q.push(i);
    }

    vector<int> order;
    while (!q.empty()) {
        int v = q.front(); q.pop();
        order.push_back(v);

        for (size_t i = 0; i < adj[v].size(); i++) {
            int u = adj[v][i];
            indegree[u]--;
            if (indegree[u] == 0) q.push(u);
        }
    }

    if ((int)order.size() != n) {
        cout << "Impossible"<<endl;
    } else {
        cout << "Possible"<<endl;
        for (size_t i = 0; i < order.size(); i++) {
            cout << order[i] << " ";
        }
        cout << endl;
    }

    return 0;
}
