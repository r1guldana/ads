#include <bits/stdc++.h>
using namespace std;
void quick_sort(vector<int> &a, int l, int r)
{
    if (l >= r) return;
    int mid = a[(l + r) / 2];
    int i = l;
    int j = r;

    while (i <= j)
    {
        while (a[i] < mid)
            i++;
        while (a[j] > mid)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (l < j)
        quick_sort(a, l, j);
    if (i < r)
        quick_sort(a, i, r);
}

int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> arr1(n);
    vector<int> arr2(m);
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    if (n > 0) quick_sort(arr1, 0, n - 1);
    if (m > 0) quick_sort(arr2, 0, m - 1);

    int i = 0;
    int j = 0;
    while (i < n && j < m)
    {
        if (arr1[i] == arr2[j])
        {
            cout << arr1[i] << " ";
            i++;
            j++;
        }
        else if (arr1[i] < arr2[j])
        {
            i++;
        }
        else
        {
            j++;
        }
    }
}