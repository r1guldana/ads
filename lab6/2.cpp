#include <bits/stdc++.h>

using namespace std;

void merge(vector<int>& arr, int l, int mid, int r){ // l....mid...r
    int n1 = mid - l+ 1;
    int n2 = r-mid;
    vector<int> L(n1);
    vector<int> R(n2);
    for(int i = 0 ; i<n1 ; i++){
        L[i] = arr[l+i];
    }
    for(int i = 0 ; i<n2 ; i++){
        R[i] = arr[mid+i+1] ;
    }
    int i =0;
    int j =0; 
    int k = l ;
    while(i<n1 && j<n2){
        if(L[i]<=R[j]){
            arr[k] = L[i] ;
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
    
}

void mergeSort(vector<int>& arr, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2 ;
        mergeSort(arr, l, mid);
        mergeSort(arr, mid+1, r);
        merge(arr, l, mid, r);

    }

}

int main() {
    int n ;
    cin >> n;
    vector<int>a(n);
    for (int i = 0 ; i < n ; i++){
        cin >> a[i] ;   
    }
    mergeSort(a, 0, n-1);
    for (int i = 0 ; i < n ; i++){
        cout << a[i] << " " ;   
    }
    return 0;
}