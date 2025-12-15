#include <bits/stdc++.h>
using namespace std;

struct DSU
{
    vector<int> parent, rank;
    DSU(int n) : parent(n), rank(n, 0)
    {
        iota(parent.begin(), parent.end(), 0);
    }
    int find(int v)
    {
        if (parent[v] == v)
            return v;
        return parent[v] = find(parent[v]);
    }
    bool unite(int a, int b)
    {
        a = find(a);
        b = find(b);
        if (a == b)
            return false;
        if (rank[a] < rank[b])
            swap(a, b);
        parent[b] = a;
        if (rank[a] == rank[b])
            rank[a]++;
        return true;
    }
};

struct Edge
{
    int u, v;
    long long w;
    bool operator<(const Edge &other) const { return w < other.w; }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<pair<long long, long long>> coords(n);
    if (n == 1)
    {
        cout << 0 << "\n";
        return 0;
    }

    for (int i = 0; i < n; i++)
        cin >> coords[i].first >> coords[i].second;

    vector<Edge> edges;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            long long w = abs(coords[i].first - coords[j].first) +
                          abs(coords[i].second - coords[j].second);
            edges.push_back({i, j, w});
        }
    }

    sort(edges.begin(), edges.end());
    DSU dsu(n);

    for (auto &e : edges)
    {
        dsu.unite(e.u, e.v);
        if (dsu.find(0) == dsu.find(n - 1))
        {
            cout << e.w << "\n";
            return 0;
        }
    }
    
}
