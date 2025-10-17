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
    int N;
    cin >> N ;
    vector<int> arr(N) ;
    for (int i = 0; i < N; i++)
    {
        cin>> arr[i] ;
    }
    quick_sort(arr, 0, N-1);
    int i = 0;
    int min_diff = INT_MAX;
    for (int i = 1; i < N; i++) {
        int diff = abs(arr[i] - arr[i - 1]);
        min_diff = min(min_diff, diff);
    }
    for (int i = 1; i < N; i++) {
        if (abs(arr[i] - arr[i - 1]) == min_diff) {
            cout << arr[i - 1] << " " << arr[i] << " ";
        }
    }
    
}