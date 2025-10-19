#include <bits/stdc++.h>
using namespace std;
void sort_column(vector<vector<int> > &matrix, int col_index, int l, int r)
{
    if (l >= r)
        return;
    int mid = matrix[(l + r) / 2][col_index];
    int i = l;
    int j = r;

    while (i < j)
    {
        while (matrix[i][col_index] > mid)
            i++;
        while (matrix[j][col_index] < mid)
            j--;

        if (i <= j)
        {
            swap(matrix[i][col_index], matrix[j][col_index]);
            i++;
            j--;
        }
    }
    if (l < j)
        sort_column(matrix, col_index, l, j);
    if (i < r)
        sort_column(matrix, col_index, i, r);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int> > matrix(n, vector<int>(m));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> matrix[i][j];
        }
    }
    for (int j = 0; j < m; j++)
    {
        if (!matrix.empty())
        {
            sort_column(matrix, j, 0, matrix.size() - 1);
        }
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}