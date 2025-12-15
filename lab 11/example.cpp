#include <bits/stdc++.h>
using namespace std ;
// DSU

int n, m, x, y, w;
vector < pair<int, int> > g[100];
vector<pair<int, pair<int, int> > > gg;
int d[100];
int u[100];
int p[100];
int r[100];
int find(int v){
    if(v == p[v]) return v ;
    p[v] = find(p[v]) ;
    return p[v];   
}

void union_s(int v, int u ){
    v = find(v);
    u = find(u);
    if(p[v] < r[u]){
        p[u] = u ;
    }
    else if(r[v] > r[u]){
        p[u] = v ;
    }
    else{
        p[u] = v ;
        r[u] ++ ;
    }
}



int main(){
    cin>>n>>m ;
    for (int i = 0; i < m; i++)
    {
        cin >> x>>y>>w ;
        x--;
        y--;
        g[x].push_back(make_pair(y, w));
        g[x].push_back(make_pair(x, w));
    }
    int INF = 100000;
    for (int i = 0; i < n; i++)
    {
        d[i] = INF;
    }
    d[0] = 0;

    sort(gg.begin(), gg.end());
    for (int i = 0; i < n; i++)
        p[i] = i;

    for (int i = 0; i < m; i++) {
        int x = gg[i].second.first;
        int y = gg[i].second.second;
        if (find(x) != find(y)) {
            union_s(x, y); 
            cout << x + 1 << " " << y + 1 << endl;
        }
    }
    for (int i = 0; i < n; i++)
    {
        int v = -1 ;
        for(int j =0 ; j<n; j++){
            if(u[j] == 0)
                if(v==-1 || d[v]>d[j]) v = j ;

        }
        u[v] = true ;

        for(int j = 0 ; j<g[v].size(); j++){
            int k = g[v][j].first;
            int l = g[v][j].second;

            if(u[k] == false && d[k] > 1){
                d[k] = l;
                p[k] = v;
            }
        }
    }
    
    for (int j = 0; j < n; j++)
        if (p[j] != j)
            cout << j + 1 << " " << p[j] + 1 << endl;
    return 0;
}