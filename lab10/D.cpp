#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void BFS(queue<int> &q, vector<vector<int> > &adj, vector<int> &dist)
{
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (int i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if (dist[u] > dist[v] + 1)
            {
                dist[u] = dist[v] + 1;
                q.push(u);
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m, q;
    cin >> n >> m >> q;

    vector<vector<int> > g(n + 1);
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }

    vector<int> dist(n + 1, INF);
    queue<int> bfs;
    while (q--)
    {
        int type, v;
        cin >> type >> v;
        if (type == 1)
        {
            if (dist[v] > 0)
            {
                dist[v] = 0;
                bfs.push(v);
                BFS(bfs, g, dist);
            }
        }
        else
        {
            cout << (dist[v] == INF ? -1 : dist[v]) << endl;
        }
    }

    return 0;
}