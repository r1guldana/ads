#include <bits/stdc++.h>
using namespace std;

int n, m;
vector<string> grid;
bool visited[100][100];

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

bool inside(int x, int y) {
    return x >= 0 && x < n && y >= 0 && y < m;
}

void dfs(int x, int y) {
    visited[x][y] = true;
    for (int dir = 0; dir < 4; dir++) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        if (inside(nx, ny) && !visited[nx][ny] && grid[nx][ny] == '1') {
            dfs(nx, ny);
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> n >> m;
    grid.resize(n); //size()
    for (int i = 0; i < n; i++) {
        cin >> grid[i];
    }

    int islands = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visited[i][j] && grid[i][j] == '1') {
                dfs(i, j);
                islands++;
            }
        }
    }

    cout << islands << endl;
    return 0;
}
