#include <bits/stdc++.h>
using namespace std;

const int MAXN = 1000005;
vector<int> adj[MAXN];
bool visited[MAXN];
bool recStack[MAXN];
int parent[MAXN];
int n, m;
int cycle_start = -1, cycle_end = -1;
bool found_cycle = false;

bool DFS_cycle_directed(int v)
{
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];

        if (!visited[u])
        {
            parent[u] = v;
            if (DFS_cycle_directed(u))
                return true;
        }
        else if (recStack[u])
        {
            cycle_start = u;
            cycle_end = v;
            found_cycle = true;
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool dfs_check(int v, int skip_u, int skip_v)
{
    visited[v] = true;
    recStack[v] = true;

    for (int i = 0; i < adj[v].size(); i++)
    {
        int u = adj[v][i];
        if (v == skip_u && u == skip_v)
            continue;

        if (!visited[u])
        {
            if (dfs_check(u, skip_u, skip_v))
                return true;
        }
        else if (recStack[u])
        {
            return true;
        }
    }

    recStack[v] = false;
    return false;
}

bool hasCycleWithSkip(int skip_u, int skip_v)
{
    fill(visited, visited + n + 1, false);
    fill(recStack, recStack + n + 1, false);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i])
        {
            if (dfs_check(i, skip_u, skip_v))
                return true;
        }
    }
    return false;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    fill(visited, visited + n + 1, false);
    fill(recStack, recStack + n + 1, false);
    fill(parent, parent + n + 1, -1);

    for (int i = 1; i <= n; i++)
    {
        if (!visited[i] && !found_cycle)
        {
            DFS_cycle_directed(i);
        }
    }
    if (!found_cycle)
    {
        cout << "YES" << endl;
        return 0;
    }
    vector<pair<int, int> > cycle_edges;
    cycle_edges.push_back(make_pair(cycle_end, cycle_start));
    int v = cycle_end;
    while (v != cycle_start)
    {
        int u = parent[v];
        cycle_edges.push_back(make_pair(u, v));
        v = u;
    }
    for (int i = 0; i < (int)cycle_edges.size(); i++)
    {
        int u = cycle_edges[i].first;
        int v2 = cycle_edges[i].second;

        if (!hasCycleWithSkip(u, v2))
        {
            cout << "YES\n";
            return 0;
        }
    }

    cout << "NO\n";
    return 0;
}