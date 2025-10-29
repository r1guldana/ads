#include <bits/stdc++.h>
using namespace std;
void merge_sort(vector<int>& a, int l, int r, int mid){
    int n1 = mid-l+1;
    int n2 = r-mid;
    vector<int> L(n1), R(n2);
    for (int i = 0; i < n1; i++)
        L[i] = a[l+i];
    for (int j = 0; j < n2; j++)
        R[j] = a[mid+1+j];
    
    int i = 0 ; //left arr
    int j = 0 ;//right arr
    int k = l; 

    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            a[k]=L[i];  // k=l
            i++;
        }
        else{
            a[k]= R[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = L[i];
        i++;
        k++;
    }
     while (j<n2)
    {
        a[k] = R[j];
        j++;
        k++;
    }
}
void mergeSort(vector<int>& a, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge_sort(a, l, r, mid);
    }
}
int main(){
    int n;
    cin>>n;
    vector<int>a(n);
    for (int i = 0; i <n; i++)
    {
        cin>>a[i];
    }
    int m;
    cin>>m;
    vector<int>b(m);
    for (int i = 0; i <m; i++)
    {
        cin>>b[i];
    }
    vector<int>arr;
    for (int i = 0; i < n; i++)
    {
       arr.push_back(a[i]);
    }
    for (int i = 0; i < m; i++)
    {
       arr.push_back(b[i]);
    }
    mergeSort(arr, 0, n+m-1);
    for (int i = 0; i < arr.size(); i++)
    {
        cout<<arr[i]<< " ";
    }
    cout << endl;
    return 0;
}
