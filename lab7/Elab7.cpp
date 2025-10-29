#include <bits/stdc++.h>
using namespace std;
long long  count_sum(vector<long long>&a){
    long long count= 0;
    for (int i = 0; i < a.size(); i++){
        count+=a[i];
    }
    return count;   
}
bool compare(vector<long long>& a, vector<long long>& b) {
    long long sum_a = count_sum(a);
    long long sum_b = count_sum(b);
    if (sum_a != sum_b) {
        return sum_a > sum_b;
    }
    for (int i = 0; i < a.size(); i++)
    {
        if(a[i] != b[i]){
            return a[i] < b[i];
        }
    }
    return false;
}
void merge (vector<vector<long long> >& a /*row*/ , int l, int mid, int r){
    int n1= mid+1-l;
    int n2 = r-mid;
    vector<vector<long long> > L1(n1), R1(n2);
    for(int i=0;i<n1; i++){
        L1[i] = a[i+l];
    }
    for(int j=0;j<n2; j++){
        R1[j] = a[mid+j+1];
    }
    int i = 0;
    int j = 0;
    int k = l;
    while(i<n1 && j<n2){
        if(compare(L1[i], R1[j])){
            a[k]=L1[i];  
            i++;
        }
        else{
            a[k]= R1[j];
            j++;
        }
        k++;
    }
    while (i<n1)
    {
        a[k] = L1[i];
        i++;
        k++;
    }
     while (j<n2)
    {
        a[k] = R1[j];
        j++;
        k++;
    }
}
void mergeSort(vector<vector<long long> >& a, int l, int r){
    if(l<r){
        int mid = l+(r-l)/2;
        mergeSort(a, l, mid);
        mergeSort(a, mid+1, r);
        merge(a, l, mid, r);
    }
}
    
int main(){
  ios::sync_with_stdio(false);
  cin.tie(NULL);
    
    int n, m;
    cin >> n>>m;
    vector<vector<long long> >  nums(n, vector<long long>(m)); ;
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < m; j++){
            cin>>nums[i][j];
        }  
    }
    mergeSort(nums, 0, n-1);
    for (int i = 0; i < n; i++){
        int count = 0;
        for (int j = 0; j < m; j++){
            cout << nums[i][j]<< " ";
        }  
        cout<< endl;
    }
    return 0;
}