#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n, m;
    cin >> n >> m;

    vector<vector<int> > grid(n, vector<int>(m));
    queue<pair<int, int> > q;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 2)
            {
                q.push(make_pair(i, j)); 
            }
        }
    }

    int minutes = 0;

    // BFS
    while (!q.empty())
    {
        int sz = q.size();
        bool crushed = false;

        for (int i = 0; i < sz; i++)
        {
            pair<int, int> p = q.front(); 
            q.pop();
            int x = p.first;
            int y = p.second;

            for (int k = 0; k < 4; k++)
            {
                int nx = x + dx[k];
                int ny = y + dy[k];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m)
                    continue;

                if (grid[nx][ny] == 1)
                {
                    grid[nx][ny] = 2;
                    q.push(make_pair(nx, ny)); 
                    crushed = true;
                }
            }
        }

        if (crushed)
            minutes++;
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (grid[i][j] == 1)
            {
                cout << -1 << endl;
                return 0;
            }
        }
    }

    cout << minutes << endl;
    return 0;
}
