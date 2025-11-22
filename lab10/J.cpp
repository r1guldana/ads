#include <bits/stdc++.h>
using namespace std;

const int MAXN = 100005;
vector<int> adj[MAXN];
bool visited[MAXN];
int children[MAXN];
int parent[MAXN];
int n, m;

void bfs_component(int root)
{
    queue<int> q;
    visited[root] = true;
    parent[root] = -1;
    q.push(root);

    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (size_t i = 0; i < adj[v].size(); i++)
        {
            int u = adj[v][i];
            if (!visited[u])
            {
                visited[u] = true;
                parent[u] = v;
                q.push(u);
                children[v]++;
            }
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        adj[x].push_back(y);
        adj[y].push_back(x);
    }

    int bigfam_count = 0;

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            int root = i;
            queue<int> q;
            q.push(i);
            visited[i] = true;
            vector<int> comp;
            comp.push_back(i);

            while (!q.empty())
            {
                int v = q.front();
                q.pop();
                for (size_t j = 0; j < adj[v].size(); j++)
                {
                    int u = adj[v][j];
                    if (!visited[u])
                    {
                        visited[u] = true;
                        q.push(u);
                        comp.push_back(u);
                    }
                }
            }

            for (size_t j = 0; j < comp.size(); j++)
            {
                visited[comp[j]] = false;
                children[comp[j]] = 0;
                parent[comp[j]] = -1;
                if (comp[j] < root)
                    root = comp[j];
            }

            bfs_component(root);

            for (size_t j = 0; j < comp.size(); j++)
            {
                int v = comp[j];
                if (v == root)
                {
                    bigfam_count++;
                }
                else
                {
                    int p = parent[v];
                    if (children[v] > children[p])
                    {
                        bigfam_count++;
                    }
                }
            }
        }
    }

    cout << bigfam_count << endl;
    return 0;
}
