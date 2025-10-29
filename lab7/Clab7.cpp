#include <bits/stdc++.h>
using namespace std;
void Merge(vector<int> &a, int l, int mid, int r)
{
    int n1 = mid + 1 - l;
    int n2 = r - mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
    {
        L[i] = a[l + i];
    }
    for (int j = 0; j < n2; j++)
    {
        R[j] = a[mid + j + 1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            a[k] = L[i];
            i++;
        }
        else
        {
            a[k] = R[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int> &a, int l, int r)
{
    if (l >= r)
        return;
    int mid = l + (r - l) / 2;
    mergeSort(a, l, mid);
    mergeSort(a, mid + 1, r);
    Merge(a, l, mid, r);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<int> n1(n);
    vector<int> m1(m);
    for (int i = 0; i < n; i++)
    {
        cin >> n1[i];
    }
    for (int i = 0; i < m; i++)
    {
        cin >> m1[i];
    }
    mergeSort(n1, 0, n - 1);
    mergeSort(m1, 0, m - 1);
    vector<int> common;
    int i = 0;
    int j = 0;
    while (i < n && j<m ){
        if(n1[i]==m1[j]){
            common.push_back(n1[i]);
            i++;
            j++;
        }
        else if(n1[i]>m1[j]){
            j++;
        }
        else{
            i++;
        }
    }
    for (int i = 0; i < common.size(); i++)
    {
        cout << common[i]<< " ";
    }
    

        return 0;
}